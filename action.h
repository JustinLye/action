#include<iostream>
#include<fstream>
#if !defined(__JL_ACTION_HEADER__)
#define __JL_ACTION_HEADER

namespace jl {
	enum JLenum {
		ACTION_TITLE_MAX_CHARS = 127,
		ACTION_DESC_MAX_CHARS = 255
	};
#if !defined(__JL_ACTION_CONSTANTS__)
#define __JL_ACTION_CONSTANTS__

#endif
	//static class to issues id's
	class action_id {
	private:
		static long _next_id;
		static int _action_obj_count;
		static void _load_from_file();
		static void _save_to_file();
		action_id(const action_id&) {}
		action_id(action_id&&) {}
	protected:
		action_id();
		~action_id();
		inline static int issue_id() { return _next_id++; }
	};

	//action has to have an id
	//action has a title
	//action has a description
	class base_action : public action_id {
	private:
		long _id;
		bool _is_issued;
		base_action(const base_action&) {}
		base_action(base_action&&) {}
	public:
		base_action() : action_id(), _id(0), _is_issued(false) {}
		inline void issue() {
			if (!_is_issued) {
				_id = issue_id();
				_is_issued = true;
			}
		}
		const long& id() const { return _id; }
	};

};

#endif