#pragma once
#include <new>

using HANDLE = void*;


enum Error_state
{
	dealloc_nullptr
};



class Pool final
{
public:
	Pool(size_t ele_sz)
		: m_ele_sz(ele_sz > sizeof(uintptr_t) ? ele_sz : sizeof(uintptr_t))
	{
	}

	~Pool()
	{
		free_all_chunks();
	}

	void* alloc() 
	{
		if (!m_p_free_mem)
		{
			if (!grow())
			{
				return nullptr;
			}
		}
		Link* ptr = m_p_free_mem;
		m_p_free_mem = m_p_free_mem->m_p_next_link;
		return static_cast<void*>(ptr);
	}

	void dealloc(void* p_ele) 
	{
		Link* p_link = static_cast<Link*>(p_ele);
		p_link->m_p_next_link = m_p_free_mem;
		m_p_free_mem = p_link;
	}

	void free_all_chunks()
	{
		Chunk* p_current{ m_p_chunk_head };
		while (p_current)
		{
			Chunk* p_next_ck = p_current->m_p_next_chunk;
			delete(p_current);
			p_current = p_next_ck;
		}

		m_p_chunk_head = nullptr;
		m_p_free_mem = nullptr;
		m_mem_alloc = 0;
	}

	void recycle_all_chunks()
	{
		Chunk* p_current{ m_p_chunk_head };
		ptrdiff_t num_ele = Chunk::storage_sz / m_ele_sz;

		while (p_current)
		{
			Chunk* p_next_ck = p_current->m_p_next_chunk;
			organize_chunk(p_current);
			reinterpret_cast<Link*>(&p_current->mem[(num_ele - 1) * m_ele_sz])->m_p_next_link
				= reinterpret_cast<Link*>(p_next_ck->mem);
			p_current = p_next_ck;
		}
		m_p_free_mem = reinterpret_cast<Link*> (m_p_chunk_head->mem);
	}

	int get_memory_used_mb()
	{
		return m_mem_alloc;
	}
private:
	//����
	struct Link
	{
		Link* m_p_next_link{ nullptr };
	};
	//����
	struct Chunk
	{
		enum
		{
			storage_sz = 8 * 1024 - 16
		};
		Chunk* m_p_next_chunk{ nullptr };
		char mem[storage_sz];//���Ӧ�þ��ǳ��ӵ�������
	};


	bool grow()
	{
		Chunk* p_new_ck = new(std::nothrow) Chunk;		//new һ���µĽڵ�
		if (!p_new_ck)
		{
			return false;
		}

		organize_chunk(p_new_ck);			//������ڵ���뵽 Link ������
		p_new_ck->m_p_next_chunk = m_p_chunk_head;//����ڵ��next�����ϳ��ӵ�ͷ���
		m_p_chunk_head = p_new_ck;//���ӵ�ͷ���ָ������½ڵ�
		m_p_free_mem = reinterpret_cast<Link*>(p_new_ck->mem);
		m_mem_alloc += Chunk::storage_sz + 16;
		return true;
	}
	//�ڴ���Ƭ, �ҵ���������
	void organize_chunk(Chunk* p_ck)
	{
		ptrdiff_t num_ele = Chunk::storage_sz / m_ele_sz;
		char* pstr = p_ck->mem;//�ɳ��ӵ�ͷ����pstr
		char* pend = &p_ck->mem[(num_ele - 1) * m_ele_sz];//�ѳ��ӵĵ�ǰ�洢��λ���������һ���ĵ�ַ����

		for (char* p{ pstr }; p < pend; p += m_ele_sz)
		{
			reinterpret_cast<Link*>(p)->m_p_next_link = reinterpret_cast<Link*>(p + m_ele_sz);
		}
		reinterpret_cast<Link*>(pend)->m_p_next_link = nullptr;
	}

	Pool(const Pool&) = delete;
	Pool(Pool&&) = delete;
	Pool& operator = (const Pool&) = delete;
	Pool& operator = (Pool&&) = delete;
	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;
	void operator delete (void*) = delete;
	void operator delete[](void*) = delete;

	Link* m_p_free_mem{ nullptr };
	Chunk* m_p_chunk_head{ nullptr };		//Chunk�����ͷָ��
	int m_mem_alloc{ 0 };			//���Ӧ�þ��ǵ�ǰ�ڵ��������, ���Ǵ��˼���Ԫ��
	const size_t m_ele_sz{ 8 }; //Ԫ�صĴ�С

};


template<class T>
class Object_pool final
{
public:

	int get_mem_used() const 
	{
		return m_pool.get_memory_used_mb();
	}

	int get_obj_count() const 
	{
		return m_size;
	}

	T* alloc() 
	{
		void* p_obj = m_pool.alloc();
		if (!p_obj)
		{
			return nullptr;
		}

		++m_size;
		return static_cast<T*>(p_obj);
	}

	Error_state dealloc(T* p_obj) 
	{
		if (!p_obj)
		{
			return dealloc_nullptr;
		}
		m_pool.dealloc(p_obj);
		--m_size;
	}

	void destroy_all() 
	{
		m_size = 0;
		m_pool.free_all_chunks();
	}

	void recycle_all() 
	{
		m_size = 0;
		m_pool.recycle_all_chunks();
	}
private:

	Object_pool(const Object_pool& other) = delete;
	Object_pool& operator = (const Object_pool& other) = delete;
	Object_pool(Object_pool&& other) = delete;
	Object_pool& operator = (Object_pool&& other) = delete;
	void* operator new(size_t) = delete;
	void* operator new[](size_t) = delete;
	void operator delete (void*) = delete;
	void operator delete[](void*) = delete;


	Pool m_pool{ sizeof(T) };
	int m_size{ 0 };
	const size_t m_obj_sz{ 8 };

};
