// PalindromePartitioning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

bool IsPalindrome(const std::string& s)
{
    size_t tail = s.size() - 1;
    for (size_t i = 0; i < tail; ++i, --tail)
    {
        if (s[i] != s[tail])
        {
            return false;
        }
    }

    return true;
}

void GetPartitionsHelper(const std::string& s, size_t start, std::vector<std::string>& current, std::vector<std::vector<std::string>>& result)
{
    if (start == s.size())
    {
        result.push_back(current);
        return;
    }

    for (size_t j = 1; j <= s.size() - start; ++j)
    {
        std::string sub = s.substr(start, j);
        if (IsPalindrome(sub))
        {
            current.push_back(sub);
            GetPartitionsHelper(s, j + start, current, result);
            current.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> GetPartitions(const std::string& s)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current;

    GetPartitionsHelper(s, 0, current, result);
    return result;
}

int main()
{
    while (true)
    {
        std::cout << "Enter your string (\"q\" to exit): ";
        std::string str;
        std::cin >> str;
        if (str == "q" || str == "Q")
            break;

        std::vector<std::vector<std::string>> result = GetPartitions(str);

        for (auto& r : result)
        {
            std::cout << r[0];
            for (size_t i = 1; i < r.size(); ++i)
                std::cout << ", " << r[i];
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}
