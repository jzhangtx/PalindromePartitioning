package main

import (
	"fmt"
	"strings"
)

func IsPalindrome(str string) bool {
	tail := len(str) - 1
	for i := 0; i < tail; i++ {
		if str[i] != str[tail] {
			return false
		}
		tail--
	}

	return true
}

func GetPalindromePartitions(str string, index int, r []string, result *[][]string) {
	if index == len(str) {
		c := make([]string, len(r))
		copy(c, r)
		*result = append(*result, c)
		return
	}

	for i := 1; index+i <= len(str); i++ {
		s := str[index : index+i]
		if IsPalindrome(s) {
			r = append(r, strings.Clone(s))
			GetPalindromePartitions(str, index+i, r, result)
			r = r[:len(r)-1]
		}
	}
}

func GetPartitions(s string) [][]string {
	var result [][]string
	var r []string

	GetPalindromePartitions(s, 0, r, &result)

	return result
}

func main() {
	for {
		fmt.Print("Please enter the string: ")
		var str string
		fmt.Scan(&str)
		if str == "q" || str == "Q" {
			break
		}

		result := GetPartitions(str)
		fmt.Println("The palindrome partitions of", str, "are: ")
		for _, ss := range result {
			fmt.Println(ss)
		}
		fmt.Println("")
	}
}
