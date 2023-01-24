struct node
{
	int prefix_count;
	bool isEnd;
	struct node *child[26];
}*head;

void init()
{
	head = new node();
	head->isEnd = false;
	head->prefix_count = 0;
}

void insert(string word)
{
	node *current = head;
	current->prefix_count++;
	
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';	//extrct first character of word
		if(current->child[letter] == NULL)
			current->child[letter] = new node();

		current->child[letter]->prefix_count++;
		current = current->child[letter];		
	}
	current->isEnd = true;
}

bool search(string word)
{
	node *current = head;
	for(int i = 0 ; i < word.length(); ++i)
	{
		int letter = (int)word[i] - (int)'a';
		if(current->child[letter] == NULL)
			return false;		//not found
		current = current->child[letter];
	}
	return current->isEnd;
}

int words_with_prefix(string prefix) //return the number of words whose prefix equal to this prefix
{
	node *current = head;
	for(int i = 0; i < prefix.length() ; ++i)
	{
		int letter = (int)prefix[i] - (int)'a';
		if(current->child[letter] == NULL)
			return 0;
		else
			current = current->child[letter];
	}
	return current->prefix_count;
}

