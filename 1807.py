class Solution:
    def evaluate(self, s: str, knowledge: List[List[str]]) -> str:
        # 转换knowl为字典
        paras = {i[0]: i[1] for i in knowledge}
        stack = []
        ret = ''
        # 创建转换标识符
        change = False
        for i in s:
            # 当左括号将标识符设置为True
            if i == '(':
                change = True
            elif i == ')':
                # 当遇到右括号，重置标识符与stack并开始判断knowledge
                change = False
                ret += paras.get(''.join(stack), '?')
                stack = []
            else:
                # change为False追加字符串，为True时append栈等待获取key
                if change:
                    stack.append(i)
                else:
                    ret += i
        return ret
