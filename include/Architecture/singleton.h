#ifndef SINGLETON_H
#define SINGLETON_H
template<class T>
class SingleTon
{
public:
	static T* getInstance()
	{
		if (!m_pInstance)
			m_pInstance = new T();
		return m_pInstance;
	}
protected:
	SingleTon(){};
	static T* m_pInstance;
};

template<class T>
T* SingleTon<T>::m_pInstance = 0;

#endif