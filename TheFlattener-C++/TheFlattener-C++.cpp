#define MAX_CHILDREN 100
#include <iostream>
#include <nlohmann/json.hpp>
#include <stack>
#include <sstream>
#include <chrono>  
using json = nlohmann::ordered_json;
using namespace std;

// Sample JSON string 
string sample_json_string = R"({
    "id": 123,
    "name": "test-obj",
    "children": [
    {
        "id": 1,
        "name": "test-child1",
        "parameters": {
        "param1": "val1",
        "param2": "val2",
        "param3": "val3"
        }
    },
    {
        "id": 2,
        "name": "test-child2",
        "parameters": {
        "param4": "val1",
        "param5": "val2",
        "param6": "val3"
        }
    }
    ],
    "additional": {
    "a1": "v1",
    "a2": "v2"
    }
})";

/**
 * Generates a large JSON string with a specified number of child elements.
 *
 * @param num_children The number of child objects to generate within the "children" array.
 * @return A string representing the large generated JSON structure.
 */
string generate_large_json(size_t num_children) {
    json large_json = {
        {"id", 123},
        {"name", "test-obj"},
        {"children", json::array()},
        {"additional", {
            {"a1", "v1"},
            {"a2", "v2"}
        }}
    };
    for (size_t i = 0; i < num_children; ++i) {
        large_json["children"].push_back({
            {"id", i + 1},
            {"name", "test-child" + to_string(i + 1)},
            {"parameters", {
                {"param" + to_string(i * 3 + 1), "val1"},
                {"param" + to_string(i * 3 + 2), "val2"},
                {"param" + to_string(i * 3 + 3), "val3"}
            }}
            });
    }
    return large_json.dump();
}

/**
 * Recursively flattens a JSON object into a single-level JSON object.
 * This function handles both objects and arrays by creating a key for each
 * nested element, combining parent and child keys with a separator.
 *
 * @param input The input JSON object or array to flatten.
 * @param output The resulting flattened JSON object.
 * @param prefix The current prefix for the key (used during recursion).
 * @param separator The separator to use between parent and child keys (default is '_').
 */
void flatten_json_recursion(const json& input, json& output, const string& prefix = "", const char separator = '_') {
    if (input.is_object()) {
        for (auto& [key, value] : input.items()) {
            string new_prefix = prefix.empty() ? key : prefix + separator + key;
            flatten_json_recursion(value, output, new_prefix);
        }
    }
    else if (input.is_array()) {
        for (size_t i = 0; i < input.size(); ++i) {
            string new_prefix =  prefix + separator + to_string(i);
            flatten_json_recursion(input[i], output, new_prefix);
        }
    }
    else {
        output[prefix] = input;
    }
}

/**
 * Main function to parse and flatten a large JSON string.
 * Measures the time taken to parse and flatten the JSON.
 */
int main() {
    // Generate a large JSON with 10,000 child objects
    string json_string = generate_large_json(MAX_CHILDREN);

    try {
        // Start measuring the time
        auto start_time = chrono::high_resolution_clock::now();

        // Parse the JSON string into a JSON object
        json j = json::parse(json_string);

        // Initialize an empty JSON object to hold the flattened data
        json flat_json;

        // Flatten the JSON using recursion
        flatten_json_recursion(j, flat_json);

        // Measure the end time
        auto end_time = chrono::high_resolution_clock::now();

        // Calculate and output the time taken
        chrono::duration<double> duration = end_time - start_time;
        cout << "Time taken In C++: " << duration.count() << " seconds" << endl;
        //cout << flat_json.dump(4);

    }
    catch (const exception& e) {
        // Handle any errors that may occur during JSON parsing
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}

