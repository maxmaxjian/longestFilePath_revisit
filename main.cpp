#include <iostream>
#include <string>
#include <stack>

struct TreeNode {
    std::string str;
    std::vector<std::shared_ptr<TreeNode>> children;

    TreeNode(const std::string & s) : str(s) {}
};

using pNode = std::shared_ptr<TreeNode>;

class solution {
public:
    int lengthLongestPath(const std::string & input) {
	std::vector<std::pair<int,std::string>> vec = split(input, "\n");
	
    }

private:
    int leadingTabs(const std::string & str) {
	int count = 0;
	size_t begin = str.find("\t",0);
	while (begin != std::string::npos) {
	    count++;
	    begin = str.find("\t", begin+1);
	}
	return count;
    }
    
    std::vector<std::pair<int,std::string>> split(const std::string & str, const std::string & delimiter) {
	std::vector<std::string> result;
	size_t begin(0), end;
	while (begin != std::string::npos) {
	    end = str.find(delimiter, begin);
	    result.push_back(str.substr(begin, end-begin));
	    begin = end+delimiter.length();
	}

	std::vector<std::pair<int,std::string>> rtn;
	for (auto & s : result) {
	    int numTabs = leadingTabs(s);
	    rtn.push_back(std::make_pair(numTabs, s.substr(2*numTabs)));
	}
	return rtn;
    }
};
