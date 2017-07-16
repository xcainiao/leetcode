class Solution(object):
    def exclusiveTime(self, n, logs):
        """
        :type n: int
        :type logs: List[str]
        :rtype: List[int]
        """
        result = [0]*n
        stack = []
        for log in logs:
            # print log
            three = log.split(':')
            index1 = int(three[0]) # task id
            index2 = three[1]      # task status
            index3 = int(three[2])  # time
            if index2 == "start":
                if stack:
                    tmp = stack.pop()
                    stack.append(tmp)                    
                    tmp1 = tmp[0]
                    tmp2 = tmp[1]
                    result[tmp1] = result[tmp1] + index3 - tmp2
                    print tmp1, result[tmp1]
                    stack.append((index1, index3))
                else:
                    stack.append((index1, index3))
            else:
                tmp = stack.pop()
                tmp1 = tmp[0]
                tmp2 = tmp[1]
                result[tmp1] = result[tmp1] + index3 - tmp2 + 1
                print tmp1, result[tmp1]
                if stack:
                    tmp = stack.pop()
                    tmp1 = tmp[0]
                    tmp2 = index3 + 1
                    stack.append((tmp1, tmp2))
        #result[0] = result[0]-1;
        return result


n = 2
logs = ["0:start:0", "1:start:2", "1:end:5", "0:end:6"]
#n = 1
#logs = ["0:start:0","0:start:2","0:end:5","0:start:6","0:end:6","0:end:7"]
a = Solution()
result = a.exclusiveTime(n, logs)
print result
