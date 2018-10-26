
# coding: utf-8

# In[1]:


from sklearn import tree


# In[2]:


import pandas as pd 
import numpy as np


# In[3]:


dataset = pd.read_csv("a.csv")


# In[4]:


X  = dataset.drop(['TQ'] ,1)
Y = dataset[['TQ']]


# In[5]:


clf = tree.DecisionTreeClassifier()


# In[6]:


clf = clf.fit(X,Y)


# In[125]:


def pred(arr):
    prediction = clf.predict([arr])
    c=prediction[0]
    print(c)
    arr1=arr-c
    arr1=list(map(abs,arr1))
    if(arr[arr1.index(min(arr1))]==0):
        return(max(arr))
    return(arr[arr1.index(min(arr1))])


# In[126]:


def wait():
    p='c'
    while(p!='p'):
        f=open("sema.txt","r")
        p=f.read(1)
        f.close()


# In[127]:


def signal():
    f=open("sema.txt","w")
    f.write("c")
    f.close()


# In[128]:

while(1):
    wait()
    f=open("s.txt","r")
    p=f.readline()
    f.close()
    p=list(map(int,p.split(',')))
    i=pred(p)
    f=open("s.txt","w")
    f.write(str(i))

    f.close()
    signal()


# In[114]:





# In[116]:





# In[117]:




