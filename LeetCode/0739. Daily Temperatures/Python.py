from typing import List

class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        answer = [0] * len(temperatures)
        stack = []
        
        for i, temperature in enumerate(temperatures):
            while stack and temperature > temperatures[stack[-1]]:
                last = stack.pop()
                answer[last] += i - last
            stack.append(i)     
        return answer

if __name__ == '__main__':
    S = Solution()
    temperatures = [73,74,75,71,69,72,76,73]
    
    print(S.dailyTemperatures(temperatures))
    