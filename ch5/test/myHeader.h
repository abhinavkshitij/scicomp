template<class T>
class abc
{
private:
	T val;	
public:
	abc(T i);
	T show();	
};

extern template class abc<int>;
