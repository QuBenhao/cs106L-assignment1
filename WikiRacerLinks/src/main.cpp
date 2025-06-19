#include <iostream>
#include <fstream>
#include <unordered_set>
#include <algorithm>
#include <iterator>

using std::cout;            using std::endl;
using std::string;          using std::unordered_set;

/*
 * Note that you have to pass in the file as a single string
 * into the findWikiLinks function!
 * So we have to turn the passed-in file into a single string...
 * does that sound familiar at all?
 */
unordered_set<string> findWikiLinks(const string& page_html) {
    unordered_set<string> links;
    auto it = page_html.begin();
    while (it != page_html.end()) {
        it = std::search(it, page_html.end(), "<a href=\"");
        if (it == page_html.end()) break; // No more links found

        it += 9; // Move past "<a href=\""
        auto end_it = std::find(it, page_html.end(), '"'); // Find the closing quote
        if (end_it != page_html.end()) {
            string link(it, end_it);
            if (link.find("/wiki/") == 0 && link.find(":") == string::npos) { // Check if it's a valid wiki link
                links.insert(link);
            }
            it = end_it + 1; // Move past the closing quote
        } else {
            break; // No closing quote found, exit loop
        }
    }
    return links;
}

int main() {
    /* Note if your file reading isn't working, please go to the
     * projects tab on the panel on the left, and in the run section,
     * uncheck the "Run in terminal" box and re-check it. This
     * should fix things.
     */

    cout << "Enter a file name: ";
    string filename;
    getline(std::cin, filename);
    string page_html;

    // TODO: Create a filestream from the filename, and convert it into
    //       a single string of data called page_html (declared above)

    // Write code here
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << endl;
        return 1;
    }
    page_html.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    unordered_set<string> validLinks = findWikiLinks(page_html);

    // TODO: Print out the validLinks set above.
    //       You can print it out in any format; this is just for you
    //       to be able to compare your results with the [output] results
    //       under the /res folder.

    // Write code here
    for (const auto& link : validLinks) {
        cout << link << endl;
    }

    return 0;
}
