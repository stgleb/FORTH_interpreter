template <class T> int length(const list<T> &il)
{
	if (empty(il))
		return 0;
	else return 1+length(rest(il));
}


template <class T> list<T> ez_list(const T &one)
{
	return list<T>(one, list<T>());
}

template <class T> list<T> ez_list(const T &one, const T &two)
{
	return list<T>(one, list<T>(two, list<T>()));
}

template <class T> list<T> ez_list(const T &one, const T &two, const T &three)
{
	return list<T>(one, list<T>(two, list<T>(three, list<T>())));
}

template <class T> list<T> ez_list(const T &one, const T &two, const T &three, const T &four)
{
	return list<T>(one, list<T>(two, list<T>(three, list<T>(four, list<T>()))));
}

template <class T> list<T> ez_list(const T &one, const T &two, const T &three, const T &four, const T&five)
{
	return list<T>(one, list<T>(two, list<T>(three, list<T>(four, list<T>(five, list<T>())))));
}


template <class T> bool find(const T &i, const list<T> &il)
{
	if (empty(il))
		return false;
	else if (i == head(il))
		return true;
	else
		return find(i, rest(il));
}
template <class T> int index_of(const T &i, const list<T> &il)
{
	if (empty(il))
		return -1;
	else if (i == head(il))
		return 0;
	else {
		int where = index_of(i, rest(il));
		return where < 0 ? where : where+1;
	}
}


template <class T> bool find(bool (*f)(const T &i), const list<T> &il)
{
	if (empty(il))
		return false;
	else if (f(head(il)))
		return true;
	else
		return find(f, rest(il));
}
template <class T> const T retrieve(bool (*f)(const T &i), const list<T> &il)
{
	if (empty(il))
		throw false;
	else if (f(head(il)))
		return head(il);
	else
		return retrieve(f, rest(il));
}

template <class T> list<T> filter(bool (*f)(const T &i), const list<T> &il)
{
	if (empty(il))
		return il;
	else if (f(head(il)))
		return list<T>(head(il), filter(f, rest(il)));
	else
		return filter(f, rest(il));
}
