import requests
import json

url1 = "https://codeforces.com/api/contest.list?gym=false"
url2 = "https://codeforces.com/api/problemset.problems"
url3 = "https://codeforces.com/api/user.status?handle=BrayanD"

#data1 = requests.get(url1)
#data2 = requests.get(url2)
#data3 = requests.get(url3)

try:
	f1 = json.dumps(data1.json())
	out1 = open("contest.txt","w")
	out1.write(f1)
except:
	False

try:
	f2 = json.dumps(data2.json())
	out2 = open("problem.txt","w")
	out2.write(f2)
except:
	False

try:
	f3 = json.dumps(data3.json())
	out3 = open("submission.txt","w")
	out3.write(f3)
except:
	False
