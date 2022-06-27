from collections import Counter

def solution(colors: list[str], numbers: list[int]):
    numbers.sort()

    MaxNumber = numbers[4]
    MostColor = Counter(colors).most_common()
    MostNumber = Counter(numbers).most_common()
    isStraight = all([numbers[i] + 1 == numbers[i + 1] for i in range(4)])
    score = MaxNumber + 100

    if MostColor[0][1] == 5 and isStraight:
        score = MaxNumber + 900
    
    elif MostNumber[0][1] == 4:
        score = MostNumber[0][0] + 800

    elif MostNumber[0][1] == 3 and MostNumber[1][1] == 2:
        score = (MostNumber[0][0] * 10) + MostNumber[1][0] + 700

    elif MostColor[0][1] == 5:
        score = MaxNumber + 600

    elif isStraight:
        score = MaxNumber + 500

    elif MostNumber[0][1] == 3:
        score = MostNumber[0][0] + 400

    elif MostNumber[0][1] == 2 and MostNumber[1][1] == 2:
        Max = max(MostNumber[0][0], MostNumber[1][0])
        Min = min(MostNumber[0][0], MostNumber[1][0])
        score = (Max * 10) + Min + 300

    elif MostNumber[0][1] == 2:
        score = MostNumber[0][0] + 200

    return score


if __name__ == '__main__':
    colors = list()
    numbers = list()

    for _ in range(5):
        color, number = input().split()
        number = int(number)

        colors.append(color)
        numbers.append(number)

    print(solution(colors, numbers))