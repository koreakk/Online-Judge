from typing import List

class Solution:
    def diffWaysToCompute(self, expression: str) -> List[int]:
        def compute(A: List[int], B: List[int], operator: str) -> List[int]:
            results = []
            for i in A:
                for j in B:
                    results.append(eval(str(i) + operator + str(j)))
            return results
        
        if expression.isdigit():
            return [int(expression)]

        results = []
        for index, value in enumerate(expression):
            if value in '+-*':
                A = self.diffWaysToCompute(expression[:index])
                B = self.diffWaysToCompute(expression[index + 1:])

                results.extend(compute(A, B, value))
        return results

if __name__ == '__main__':
    expression = "2*3-4*5"
    print(Solution().diffWaysToCompute(expression))