
/**
* Desc: variables buffer
* Author: dawnarc
* Date: 2016-05-21
* Time: 14:49
*/

#pragma once

namespace dawnarc
{
	class var_buffer
	{
	public:

		var_buffer();

		var_buffer(const var_buffer& buf);

		//����һ�˳�ʼ���ռ䣬֮�����Add����
		var_buffer(int capacity);

		//��data������䣬֮�����Get����
		var_buffer(const char* data, int size);

		~var_buffer();

		bool add_int(int value);
		bool add_float(float value);
		bool add_string(const char *value);
		bool add_bytes(const char *value, int size);
		bool add_widestr(const wchar_t *value);

		int int_() const;
		float float_() const;
		const char* string_(int &len) const;
		const char* string_() const;
		const char* bytes_(int& size) const;
		const char *data() const;
		size_t size() const;
		char* now_data();

		//if want to re-add value after get value, must invoke flush() to clean read and write sign.
		void flush();

		//��������buff���������ƣ����ô�API���û�Ұ��ʹ�������ڴ����⡣
		//�����ô�API���ټ������ڴ�Ҳ������ģ����Ƕ�����ͨ���߼����ǿ϶��������ˡ�
		static void set_capaticy_range(int min, int max)
		{
			MIN_CAPACITY = min;
			MAX_CAPACITY = min;
		}

	private:
		static int MIN_CAPACITY;
		static int MAX_CAPACITY;
		inline bool ensure_capacity(int leastLen);

	private:
		int m_capacity;
		char *m_data;
		char *m_write;
		mutable char *m_read;
	};

	inline var_buffer& operator<<(var_buffer & v, int value)
	{
		v.add_int(value);
		return v;
	}

	inline var_buffer& operator<<(var_buffer & v, float value)
	{
		v.add_float(value);
		return v;
	}

	inline var_buffer& operator<<(var_buffer & v, const char *value)
	{
		v.add_string(value);
		return v;
	}

	inline var_buffer& operator<<(var_buffer & v, const wchar_t *value)
	{
		v.add_widestr(value);
		return v;
	}
}