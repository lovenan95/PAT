import requests
import json
import time

with open("patb.json",'rb') as load_f:
    load_dict = json.load(load_f)

id_list = []
for item in load_dict['problemSetProblems']:
    id_list.append({'id':item['id'],'title':item['title'],'label':item['label']})

cookies = "copy from chrome headers cookie"
cookie = {'Cookie': cookies}
for item in id_list:
    #甲级
    urla = "https://pintia.cn/api/problem-sets/994805342720868352/problems/"+item['id']+"?exam_id=1008371401626570752"
    #乙级
    urlb = "https://pintia.cn/api/problem-sets/994805260223102976/problems/"+item['id']+"?exam_id=1120104"
    print(urla)
    response = requests.get(urlb,cookies=cookie)
    restext = response.text
    res = json.loads(restext)
    print(res)
    if(res["problemSetProblem"]["lastSubmissionId"]=="0"):
        continue
    code = res["problemSetProblem"]["lastSubmissionDetail"]["programmingSubmissionDetail"]["program"]
    if(code == ""):
        continue
    with open("C:\\Users\\Administrator\\Desktop\\patb_code\\PAT-B"+item['label']+" "+item['title']+".cpp", "w", encoding='utf-8') as f:
        f.write(code)
    time.sleep(2)  # delays for 2 seconds

