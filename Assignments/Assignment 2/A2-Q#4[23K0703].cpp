#include <iostream>
#include <functional>

using namespace std;

class User
{
    string username, email;
    size_t password;

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

    size_t hash(string password)
    {
        return std::hash<string>{}(password);
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
        for (int i = 0; i < 10; i++)
            comments[i] = "";
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

    void addToFeed(Post *post)
    {
        if (numPostsPosted < 5)
        {
            numPostsPosted++;
            feed[numPostsPosted - 1] = post;
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

public:
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

    void promotePost(Post *post)
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
                post->promoteLikes();
                post->promoteViews();

                promotedPosts[numPostsPromoted] = post;
                numPostsPromoted++;
            }
        }
    }

    void viewPromotedPosts()
    {
        for (int i = 0; i < numPostsPromoted; i++)
        {
            promotedPosts[i]->display();
        }
    }
};

int main()
{
    // Solution Header
    cout << "Name: Sarim Ahmed" << endl;
    cout << "ID: 23K0703" << endl
         << endl;

    Post *post1 = new Post("12345", "I love getting killed.");
    Post *post2 = new Post("12344", "After life is a high.");
    Post *post3 = new Post("12342", "I love killing people.");

    RegularUser user1("uwuMurderer", "12398ru23", "murder@hehe.com");
    RegularUser user2("waitingToBeMurdered", "3r4t34t43t", "murdered@haha.com");
    BusinessUser user3("murderPromoter786", "1234", "murderIsProductive@business.com");

    post1->like();
    post1->like();
    post1->like();
    post1->like();

    post2->like();
    post2->like();
    post2->like();

    post3->like();

    post3->comment("Great initiative");

    user2.addToFeed(post1);
    user2.addToFeed(post2);
    user2.addToFeed(post3);

    user2.viewFeed();
    user2.viewFeed();

    user3.promotePost(post1);
    user3.promotePost(post2);

    user3.viewPromotedPosts();
}