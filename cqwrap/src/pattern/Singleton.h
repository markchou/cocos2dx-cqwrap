#ifndef __Weizoo_Singleton_H__
#define __Weizoo_Singleton_H__

#include "cocos-ext.h"

NS_CC_EXT_BEGIN

template <class T>
class Singleton
{
public:
	static inline T* getInstance();
	void dropInstance();
protected:
	Singleton(void){}
	~Singleton(void){}
	static T* s_instance;
};

template <class T>
inline T* Singleton<T>::getInstance()
{
	if(!s_instance)
		s_instance = new T;
	return s_instance;
}

template <class T>
void Singleton<T>::dropInstance()
{
	if (!s_instance)
		return;
	CC_SAFE_DELETE(s_instance);
	s_instance = 0;
}

NS_CC_EXT_END

#define DECLARE_SINGLETON_MEMBER(_Ty)	\
	template <> _Ty* weizoo::Singleton<_Ty>::s_instance = NULL;

#endif//__Weizoo_Singleton__
