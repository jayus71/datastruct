import os

# 指定要修改的目录路径
directory = 'C:\\Users\\Jayus\\Desktop'

# 遍历目录下的所有文件和子目录
for root, dirs, files in os.walk(directory):
    for file in files:
        # 只修改以 .txt 结尾的文件
        if file.endswith('.txt'):
            file_path = os.path.join(root, file)
            # 执行文件修改操作，这里假设修改操作是在文件名后添加 '_modified'
            new_file_path = os.path.join(root, file.split('.')[0] + 'test_modified2.txt')
            os.rename(file_path, new_file_path)

print("done!")