#include "action.h"
namespace jl {
	const char* ACTION_ID_SAVE_FILE = "action_id.dat";
	const char* ACTION_ERR_SAVE_FILE_OPEN_FAIL =
		"ERROR::action_id::_save_to_file()::Output file could not be opened. Next id failed to be saved.";
}
int jl::action_id::_action_obj_count = 0;
long jl::action_id::_next_id = 0;

void jl::action_id::_load_from_file() {
	std::ifstream input_file;
	input_file.open(jl::ACTION_ID_SAVE_FILE);
	if (!input_file) {
		_next_id = 1;
	}
	else {
		input_file >> _next_id;
		input_file.close();
	}

}

void jl::action_id::_save_to_file() {
	std::ofstream output_file;
	output_file.open(jl::ACTION_ID_SAVE_FILE);
	if (!output_file) {
		std::cerr << jl::ACTION_ERR_SAVE_FILE_OPEN_FAIL << std::endl;
		return;
	}
	output_file << _next_id;
	output_file.close();
}

jl::action_id::action_id() {
	if (_action_obj_count == 0) {
		jl::action_id::_load_from_file();
	}
	_action_obj_count++;
}
jl::action_id::~action_id() {
	_action_obj_count--;
	if (_action_obj_count <= 0) {
		jl::action_id::_save_to_file();
	}
}
