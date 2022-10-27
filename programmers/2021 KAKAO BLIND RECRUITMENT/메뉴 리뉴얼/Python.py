from collections import Counter
from itertools import combinations

def solution(orders, course):
    answer = []

    for r in course:
        most_ordered = Counter(
            sum((list(combinations(sorted(order), r))
                    for order in orders), []
            )
        ).most_common()
        
        if not most_ordered: continue
        max_sub = max(2, most_ordered[0][1])
        answer.extend(''.join(s) for s, r in most_ordered if r == max_sub)

    return sorted(answer)