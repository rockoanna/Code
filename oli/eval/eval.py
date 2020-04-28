import sys
import os
import subprocess
import time
 
def compare_files(fpath1, fpath2):
    with open(fpath1, 'r') as file1, open(fpath2, 'r') as file2:
        for linef1, linef2 in zip(file1, file2):
            linef1 = linef1.rstrip('\r\n')
            linef2 = linef2.rstrip('\r\n')
            if linef1 != linef2:
                return False
        return next(file1, None) == None and next(file2, None) == None
 
def apply(directory, name, exe):
    for filename in os.listdir(directory):
        if filename.endswith(".in"):
            test_file_path = os.path.join(directory, filename)
            #print("Testing ", filename)
            subprocess.call(["cp", test_file_path, '{}.in'.format(name)])            
            start_time = time.time()
            res = subprocess.call(exe)            
            end_time = time.time()            
            if res != 0:
                print("{} CRASHED {} ms".format(filename, round((time.time() - start_time)*1000, 3)))
            else:                
                expected = os.path.splitext(test_file_path)[0]+'.ok'                
                actually = '{}.out'.format(name)                
                if compare_files(expected, actually):
                      print("{} GOOD {} ms".format(filename, round((time.time() - start_time)*1000, 3)))
                else:
                      print("{} BAD {} ms".format(filename, round((time.time() - start_time)*1000, 3)))
                subprocess.call(["mv", actually, '{}.out'.format(os.path.splitext(filename)[0])])                  
    subprocess.call(["rm", '{}.in'.format(name)])
 
 
 
directory = sys.argv[1]
name = sys.argv[2]
exe = sys.argv[3]
apply(directory, name, exe)
