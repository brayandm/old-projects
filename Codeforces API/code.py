import json

out = open("C++/data.out","w")

contest = json.loads(open("Datos/contest.txt","r").read())["result"]
problem = json.loads(open("Datos/problem.txt","r").read())["result"]["problems"]
submission = json.loads(open("Datos/submission.txt","r").read())["result"]

data = {}

for i in range(len(contest)):
	c_id = contest[i]["id"];
	data[c_id] = [contest[i]["name"],[],[],[]];

for i in range(len(problem)):
	try:
		c_id = problem[i]["contestId"]
		
		try:
			txt = str(problem[i]["contestId"])+problem[i]["index"]+" "+str(problem[i]["rating"])
		except:
			txt = str(problem[i]["contestId"])+problem[i]["index"]+" "+"0"
			
		data[c_id][1].append(txt)
	except:
		continue

for i in range(len(submission)):
	try:
		c_id = submission[i]["contestId"]
		
		try:
			txt = str(submission[i]["problem"]["contestId"])+submission[i]["problem"]["index"]+" "+str(submission[i]["problem"]["rating"])
		except:
			txt = str(submission[i]["problem"]["contestId"])+submission[i]["problem"]["index"]+" "+"0"
			
		if submission[i]["verdict"] == "OK":
			data[c_id][2].append(txt)
	except:
		continue

for i in range (len(contest)):
	c_id = contest[i]["id"]

	out.write(str(c_id) + "\n")
	out.write(data[c_id][0] + "\n")
	
	s1 = set(data[c_id][1])
	s2 = set(data[c_id][2])
	s3 = s1-s2
		
	data[c_id][1] = list(s1)
	data[c_id][2] = list(s2)
	data[c_id][3] = list(s3)
	
	data[c_id][1].sort()
	data[c_id][2].sort()
	data[c_id][3].sort()
	
	for x in data[c_id][1]:
		out.write(x + " ")
	out.write("\n")		
	
	for x in data[c_id][2]:
		out.write(x + " ")
	out.write("\n")
	
	for x in data[c_id][3]:
		out.write(x + " ")
	out.write("\n")
	
	out.write("\n")
