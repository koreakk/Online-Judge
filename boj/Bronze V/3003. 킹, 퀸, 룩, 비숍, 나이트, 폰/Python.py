check = [1, 1, 2, 2, 2, 8]
chess_pieces = map(int, input().split())

for idx, piece in enumerate(chess_pieces):
    print(check[idx] - piece, end=' ')
