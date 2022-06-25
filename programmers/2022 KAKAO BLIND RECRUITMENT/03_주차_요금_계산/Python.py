def formula(time, fees):
    if time <= fees[0]: return fees[1]
    q = (time - fees[0] + fees[2] - 1) // fees[2]
    return fees[1] + q * fees[3]

def solution(fees, records):
    max_id = 10000
    end_time = 23 * 60 + 59

    times = [0] * max_id
    inTimes = [-1] * max_id
    for r in records:
        time, id, state = r.split()
        time = int(time[:2]) * 60 + int(time[3:])
        id = int(id)

        if state == 'IN':
            inTimes[id] = time
        else:   # OUT
            times[id] += time - inTimes[id]
            inTimes[id] = -1

    for id in range(max_id):
        if inTimes[id] != -1:
            times[id] += end_time - inTimes[id]


    return [formula(time, fees) for time in times if time != 0]
