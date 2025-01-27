'''
In English, we have a concept called root, which can be followed by some other word to form another longer word - let's call this word derivative. For example, when the root "help" is followed by the word "ful", we can form a derivative "helpful".

Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the derivatives in the  sentencewith the root forming it. If a derivative can be replaced by more than one root, replace it with the root that has the shortest length.

Return the sentence after the replacement.

Example 1:

Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Example 2:

Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
Output: "a a b c"
'''

class TreeNode():
    def __init__(self):
        self.child = {}
        self.finish = False

class RadixTree():
    def __init__(self, dictionary):
        self.root = TreeNode()
        if dictionary:
            for word in dictionary:
                self._rebuild(word)

    def _rebuild(self, word):
        node = self.root
        for x in word:
            if node.finish:
                # find one root
                break
            if x not in node.child:
                node.child[x] = TreeNode()
            node = node.child[x]
        node.finish = True

    def find(self, word):
        res = []
        node = self.root
        for x in word:
            if node.finish:
                break
            if x not in node.child:
                res = []
                break
            node = node.child[x]
            res.append(x)
        return "".join(res)

class Solution:
    def solution(self, dictionary, sentence):
        """
        :type dictionary: List[str]
        :type sentence: str
        :rtype: str
        """
        result = []
        root_dict = RadixTree(dictionary)
        word_list = sentence.strip().split(" ")
        for word in word_list:
            res = root_dict.find(word)
            if not res:
                result.append(word)
            else:
                result.append(res)
        return " ".join(result)

if __name__ == "__main__":
    dictionary = ["cat","bat","rat"]
    sentence = "the cattle was rattled by the battery"

    s = Solution()
    res = s.solution(dictionary, sentence)
    print(f"actual: {res}")
    print(f"target: the cat was rat by the bat")

    