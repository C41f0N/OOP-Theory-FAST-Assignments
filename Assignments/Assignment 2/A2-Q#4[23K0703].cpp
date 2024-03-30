#include <iostream>

using namespace std;

class User
{
    string username, password, email;

public:
    User(string username, string password, string email)
    {
        this->username = username;
        this->email = email;

        this->password = hash(password);
    }

    bool verifyUser(string email, string password)
    {
        return this->email == email && this->password == hash(password);
    }

    string hash(string password)
    {
        return password;
    }
};

class Post
{
    string postId, content, comments[10];
    int numComments, likes, views;

public:
    Post(string postId, string content) : postId(postId), content(content)
    {
        numComments = 0;
        likes = 0;
        views = 0;
    }

    int getViews()
    {
        return this->views;
    }

    void promoteViews()
    {
        this->views *= 3;
    }

    int getNumComments()
    {
        return this->numComments;
    }

    int getLikes()
    {
        return this->likes;
    }

    void promoteLikes()
    {
        this->likes *= 2;
    }

    void comment(string comment)
    {
        comments[numComments] = comment;
        numComments++;
    }

    void like()
    {
        likes++;
    }

    void display()
    {
        // Add view
        views++;

        cout << "\nPost ID: " << postId << endl;
        cout << "Content: " << content << endl;
        cout << "Likes: " << likes << endl;
        cout << "Views: " << views << endl;
        cout << "Comments:" << endl;
        for (int i = 0; i < numComments; i++)
        {
            cout << "Comment#" << i + 1 << ": " << comments[i] << endl;
        }
    }
};

class RegularUser : public User
{
    int numPostsPosted;
    static const int MAX_FEED_SIZE = 10;
    Post *feed[MAX_FEED_SIZE];

public:
    RegularUser(
        string username,
        string password,
        string email)
        : User(
              username,
              password,
              email)
    {
        numPostsPosted = 0;
    }

    void addToFeed(Post post)
    {
        if (numPostsPosted < 5)
        {
            feed[numPostsPosted] = &post;
            numPostsPosted++;
        }
    }

    void viewFeed()
    {
        for (int i = 0; i < numPostsPosted; i++)
        {
            feed[i]->display();
        }
    }
};

class BusinessUser : public User
{
    int numPostsPromoted;
    Post *promotedPosts[10];

    BusinessUser(
        string username,
        string password,
        string email)
        : User(
              username,
              password,
              email)
    {
        numPostsPromoted = 0;
    }

    void promotePost(Post post)
    {
        if (numPostsPromoted < 10)
        {
            string inputEmail, inputPassword;

            cout << "Enter Email: ";
            cin >> inputEmail;

            cout << "Enter Password: ";
            cin >> inputPassword;

            if (verifyUser(inputEmail, inputPassword))
            {
                post.promoteLikes();
                post.promoteViews();

                promotedPosts[numPostsPromoted] = &post;
                numPostsPromoted++;
            }
        }
    }
};

int main()
{
}