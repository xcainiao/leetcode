class MagicDictionary:
    def __init__(self):
        self.listx = []

    def buildDict(self, dict):
        self.listx = dict

    def search(self, word):
        for i in range(0, len(self.listx)):
            if(len(word) != len(self.listx[i])):
                continue
            if(word == self.listx[i]):
                continue
            diff = 0
            for y in range(0, len(word)):
                if word[y] != self.listx[i][y]:
                    diff = diff + 1
                    if diff > 1:
                        break
            if(diff == 1):
                return True
        return False

