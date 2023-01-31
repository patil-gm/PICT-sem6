import numpy as np
import pandas as pd

data = pd.read_csv('/content/AB_NYC_2019.csv')

data.shape
# the shape() method is used to fetch the dimensions of Pandas and NumPy type objects in python

data.info()
# prints information about the DataFrame. The information contains the number of columns, 
# column labels, column data types, memory usage, range index, and 
# the number of cells in each column (non-null values).

data.describe()
# returns description of the data in the DataFrame. 
# If the DataFrame contains numerical data, 
# the description contains these information for each column: 
# count - The number of not-empty values. 
# mean - The average (mean) value.

data.head()
# returns a specified number of rows, string from the top. 
# The head() method returns the first 5 rows if a number is not specified.

data.tail()
# returns a specified number of last rows. 
# The tail() method returns the last 5 rows if a number is not specified.

data.isnull()
# returns a DataFrame object where all the values are replaced with a Boolean value 
# True for NULL values, and otherwise False.

data.isnull().sum()
# returns the number of missing values in the dataset.

data.duplicated()
#  returns a Series with True and False values 
# that describe which rows in the DataFrame are duplicated and not.

data.duplicated().sum()


# FROM HERE PRICE COLUMN IS SELECTED
data.price.value_counts()

data.price.mean()

data.price.median()

data.price.mode()

data.price.std() # standard deviation

data.price.var() # variance

data.price.min()






