import math

f = open("inp.txt","r")
fout = open("out.txt","w")

list_of_lines = f.readlines()
dictValues = dict()
constantFoldedList = []








def isPerfectPower(a, b):
    while a % b == 0:
        a = a / b
    if a == 1:
        return True
    return False





print("\n")
print("Common subexpression ..")
print("--------------------")
quadruple_list=[]



for i in list_of_lines:
	# print(i)
	i = i.strip("\n")
	op,arg1,arg2,res = i.split()
	quadruple_list.append([op,arg1,arg2,res])
	

# for i in quadruple_list:
	
# 	print(i[3],'=',i[1],i[0],i[2])

# print("\n\n\n")


new_list= []; new_list1=[]; hold_list=[]
new = -1; old = -1; k =0
for i in range(0,len(quadruple_list)):
	for j in range(i+1,len(quadruple_list)):
		hold_list=[]
		if(quadruple_list[i][0]==quadruple_list[j][0] and quadruple_list[i][1]==quadruple_list[j][1] and quadruple_list[i][2]==quadruple_list[j][2]):
			hold_list.append([quadruple_list[i][0], quadruple_list[i][1], quadruple_list[i][2]])
			if(hold_list not in new_list1):
				new_list1.append(hold_list)
				vari = 't'+str(k); k+=1
				new_list.append([quadruple_list[i][0], quadruple_list[i][1], quadruple_list[i][2], vari])


print("Before modificaiton ......")
for i in quadruple_list:
	if(i[0] == "="):
		print(i[3], "=", i[1])
	else:
		print(i[3], "=", i[1], i[0], i[2])
print()



quadruple_list_new = []; k = 0
for i in range(0, len(quadruple_list)):
	for j in range(k, len(new_list)):
		if(quadruple_list[i][0]==new_list[j][0] and quadruple_list[i][1]==new_list[j][1] and quadruple_list[i][2]==new_list[j][2]):
			quadruple_list_new.append(new_list[j])
			k+=1
			break
	quadruple_list_new.append(quadruple_list[i])

"""print()
for i in quadruple_list_new:
	print(i)
print()
"""
for j in range(0,len(new_list)):
	for i in range(0,len(quadruple_list_new)):
		if(quadruple_list_new[i][0]==new_list[j][0] and quadruple_list_new[i][1]==new_list[j][1] and quadruple_list_new[i][2]==new_list[j][2] and quadruple_list_new[i][3]!=new_list[j][3]):
				quadruple_list_new[i][0] = "="
				quadruple_list_new[i][1] = new_list[j][3]
				quadruple_list_new[i][2] = "NULL"



print("After modificaiton ......")
for i in quadruple_list_new:
	if(i[0] == "="):
		print(i[3], "=", i[1])
	else:
		print(i[3], "=", i[1], i[0], i[2])

       
print("\n")
print("Strength Reduction ")
print("--------------------")
for i in list_of_lines:
	# print(i)
	i = i.strip("\n")
	op,arg1,arg2,res = i.split()
	if(arg2=='2' and op=='^'):
		print(res,"=",arg1,'*',arg1)
	
	if(op=='*'):
		if(arg2=='2'):
			print(res,"=",arg1,'+',arg1)
		elif(arg2.isnumeric() and isPerfectPower(int(arg2),2)):
			print(res,"=",arg1,'<<',int(math.log(int(arg2), 2)))
				
	if(op=='/'):
		
		if(arg2.isnumeric() and isPerfectPower(int(arg2),2)):
			print(res,"=",arg1,'>>',int(math.log(int(arg2), 2)))
		






print("Quadruple form after Constant Folding")
print("-------------------------------------")
for i in list_of_lines:
    i = i.strip("\n")
    op,arg1,arg2,res = i.split()
    if(op in ["+","-","*","/"]):
        if(arg1.isdigit() and arg2.isdigit()):
            result = eval(arg1+op+arg2)
            dictValues[res] = result
            print("=",result,"NULL",res)
            constantFoldedList.append(["=",result,"NULL",res])
        elif(arg1.isdigit()):
            if(arg2 in dictValues):
                result = eval(arg1+op+dictValues[arg2])
                dictValues[res] = result
                print("=",result,"NULL",res)
                constantFoldedList.append(["=",result,"NULL",res])
            else:
                print(op,arg1,arg2,res)
                constantFoldedList.append([op,arg1,arg2,res])
        elif(arg2.isdigit()):
            if(arg1 in dictValues):
                result = eval(dictValues[arg1]+op+arg2)
                dictValues[res] = result
                print("=",result,"NULL",res)
                constantFoldedList.append(["=",result,"NULL",res])
            else:
                print(op,arg1,arg2,res)
                constantFoldedList.append([op,arg1,arg2,res])
        
        
               
        else:
            flag1=0
            flag2=0
            arg1Res = arg1
            if(arg1 in dictValues):
                arg1Res = str(dictValues[arg1])
                flag1 = 1
            arg2Res = arg2
            if(arg2 in dictValues):
                arg2Res = str(dictValues[arg2])
                flag2 = 1
            if(flag1==1 and flag2==1):
                result = eval(arg1Res+op+arg2Res)
                dictValues[res] = result
                print("=",result,"NULL",res) 
                constantFoldedList.append(["=",result,"NULL",res])
            else:
                print(op,arg1Res,arg2Res,res)
                constantFoldedList.append([op,arg1Res,arg2Res,res])
            
    elif(op=="="):
        if(arg1.isdigit()):
            dictValues[res]=arg1
            print("=",arg1,"NULL",res)
            constantFoldedList.append(["=",arg1,"NULL",res])
        else:
            if(arg1 in dictValues):
                print("=",dictValues[arg1],"NULL",res)
                constantFoldedList.append(["=",dictValues[arg1],"NULL",res])
            else:
                print("=",arg1,"NULL",res)
                constantFoldedList.append(["=",arg1,"NULL",res])
    
    else:
        print(op,arg1,arg2,res)
        constantFoldedList.append([op,arg1,arg2,res])







					








print("\n")
print("Constant folded expression - ")
print("--------------------")
for i in constantFoldedList:
  
    if(i[0]=="="):
        print(i[3],i[0],i[1])
    elif(i[0] in ["+","-","*","/","==","<=","<",">",">="]):
        print(i[3],"=",i[1],i[0],i[2])
    elif(i[0] in ["if","goto","label","not"]):
        if(i[0]=="if"):
            print(i[0],i[1],"goto",i[3])
        if(i[0]=="goto"):
            print(i[0],i[3])
        if(i[0]=="label"):
            print(i[3],":")
        if(i[0]=="not"):
            print(i[3],"=",i[0],i[1])
            
            
                        
            
            
            

            
            
            
            

print("\n")
print("After dead code elimination - ")
print("------------------------------")
for i in constantFoldedList:
    if(i[0]=="="):
        pass
    elif(i[0] in ["+","-","*","/","==","<=","<",">",">="]):
        print(i[3],"=",i[1],i[0],i[2])
    elif(i[0] in ["if","goto","label","not"]):
        if(i[0]=="if"):
            print(i[0],i[1],"goto",i[3])
        if(i[0]=="goto"):
            print(i[0],i[3])
        if(i[0]=="label"):
            print(i[3],":")
        if(i[0]=="not"):
            print(i[3],"=",i[0],i[1])
                
        

