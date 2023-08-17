# https://realpython.com/python-sql-libraries/
import sqlite3
from sqlite3 import Error

def create_connection(path):
    connection = None
    try:
        connection = sqlite3.connect(path)
    except Exception as e:
        print("Exception: {}".format(e))
    return connection

connection = create_connection("./sample.sqlite")


def execute_query(connection, query):
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        connection.commit()
        print("Query executed successfully")
    except Exception as e:
        print("Error: ", e)
        
create_users_table = """
    CREATE TABLE IF NOT EXISTS users (
        id INTEGER PRIMARY KEY AUTOINCREMENT, 
        name TEXT NOT NULL, 
        age INTEGER, 
        gender TEXT,
        nationality TEXT
    );
"""

execute_query(connection, create_users_table)

create_posts_table = """
CREATE TABLE IF NOT EXISTS posts(
  id INTEGER PRIMARY KEY AUTOINCREMENT, 
  title TEXT NOT NULL, 
  description TEXT NOT NULL, 
  user_id INTEGER NOT NULL, 
  FOREIGN KEY (user_id) REFERENCES users (id)
);
"""
execute_query(connection, create_posts_table)

create_comments_table = """
CREATE TABLE IF NOT EXISTS comments (
  id INTEGER PRIMARY KEY AUTOINCREMENT, 
  text TEXT NOT NULL, 
  user_id INTEGER NOT NULL, 
  post_id INTEGER NOT NULL, 
  FOREIGN KEY (user_id) REFERENCES users (id) FOREIGN KEY (post_id) REFERENCES posts (id)
);
"""

create_likes_table = """
CREATE TABLE IF NOT EXISTS likes (
  id INTEGER PRIMARY KEY AUTOINCREMENT, 
  user_id INTEGER NOT NULL, 
  post_id integer NOT NULL, 
  FOREIGN KEY (user_id) REFERENCES users (id) FOREIGN KEY (post_id) REFERENCES posts (id)
);
"""

execute_query(connection, create_comments_table)  
execute_query(connection, create_likes_table) 

create_users = """
    INSERT INTO
    users (name, age, gender, nationality)
    VALUES
    ('James', 25, 'male', 'USA'),
    ('Leila', 32, 'female', 'France'),
    ('Brigitte', 35, 'female', 'England'),
    ('Mike', 40, 'male', 'Denmark'),
    ('Elizabeth', 21, 'female', 'Canada');
"""

execute_query(connection, create_users)

create_posts = """
    INSERT INTO 
        posts (title, descriptions, user_id)
    VALUES
        ("Happy", "I am feeling very happy today", 1),
        ("Hot Weather", "The weather is very hot today", 2),
        ("Help", "I need some help with my work", 2),
        ("Great News", "I am getting married", 1),
        ("Interesting Game", "It was a fantastic game of tennis", 5),
        ("Party", "Anyone up for a late-night party today?", 3);
"""
create_comments = """
    INSERT INTO
        comments (text, user_id, post_id)
    VALUES
        
"""
