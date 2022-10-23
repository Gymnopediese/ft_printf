import os


nums = [2147483647, -2147483648, 100, 1000000, 10000000000000000, 0, -100, -1000000, -10000000000000000]
fnums = ["1", "2", "4", "7", "10", "15"]
signs = ["i", "x", "X", "u"]
flags = ["0", "-", ""]
flags2 = ["."]
preflag = ["+", " ", "#"]
os.system("rm tprintf")
os.system("rm ftprintf")

for sign in signs:
	for flag in flags:
		for n in fnums:
			for flag2 in flags2:
				for n2 in fnums:
					for num in nums:
						for pf in preflag:
							print('./t_printf "%' + pf + flag + n + flag2 + n2 + sign + '" ' + str(num) +" f >> tprintf")
							os.system('./a.out "%' + pf + flag + n + flag2 + n2 + sign + '" ' + str(num) +" c")
							os.system('./a.out "%' + pf + flag + n + flag2 + n2 + sign + '" ' + str(num) +" t >> tprintf")
							os.system('./a.out "%' + pf + flag + n + flag2 + n2 + sign + '" ' + str(num) +" f >> ftprintf")
os.system("diff tprintf ftprintf")