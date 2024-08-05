from tester import Tester


def main():
    tester = Tester("./test.json")
    for test in tester:
        while True:
            print(test[0])
            for i in enumerate(test[1]):
                print(str(i[0]) + '. ' + i[1])
            responce = int(input())
            print("Respiration: ", end="")
            resp = int(input())
            print("Heart rate: ", end="")
            heart_rate = int(input())
            print("Blushing level: ", end="")
            blushing = int(input())
            print("Pupillary dilation: ", end="")
            pupil = int(input())
            resp = test[2](responce, resp, heart_rate, blushing, pupil)
            if not resp:
                print()
                break
            else:
                print('! ', resp, ' : reenter data')

    if tester.evaluate():
        print('Human')
    else:
        print('Replicant')


if __name__ == '__main__':
    main()
