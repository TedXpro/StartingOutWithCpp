class MyHashMap
{
private:
    struct keyValue
    {
        int key;
        int value;
    };

    vector<vector<keyValue>> vect;
    int setSize;

    int hashFunction(int key)
    {
        return key % setSize;
    }

    vector<struct>::iterator findKey(vector<struct>::iterator start, vector<struct>::iterator finish, key)
    {
        for (vector<struct>::iterator iter = start; iter < finish; iter++)
        {
            if ((*iter)->key == key)
                return iter;
        }
        return finish;
    }

public:
    MyHashMap()
    {
        setSize = 15000;
    }

    void put(int key, int value)
    {
        int index = hash_function(key);
        vector<struct>::iter = findKey(vect[index].begin(), vect[index].end(), key);
        if (iter != vect[index].end())
            (*iter).value = value;
        else
        {
            keyValue newKeyValue;
            newKeyValue.key = key;
            newKeyValue.value = value;
            vect[index].push_back(newKeyValue);
        }
    }

    int get(int key)
    {
        int index = hash_function(key);
        vector<struct>::iter = findKey(vect[index].begin(), vect[index].end(), key);
        if(iter == vect[index].end())
            return -1;
        return (*iter).value;
    }

    void remove(int key)
    {
        int index = hash_function(key);
        vector<struct>::iter = findKey(vect[index].begin(), vect[index].end(), key);
        if(iter != vect[index].end())
            vect[i].erase(iter);
    }
};

int main()

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */