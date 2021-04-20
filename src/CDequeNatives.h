#include "SDK/plugin.h"
#include <vector>
#include <map>
using namespace std;
class CDequeNatives{
public:
	static cell AMX_NATIVE_CALL deque(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL push_back(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL push_back_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL push_back_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL push_front(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL push_front_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL push_front_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL pop_back(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL pop_front(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_type(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL clear(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL size(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL empty(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL resize(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL remove(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL swap(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL swap_index(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL shrink_to_fit(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL is_exists(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL is_vector_exists(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL reverse(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL find(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL find_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL find_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL set(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL set_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL set_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL assign(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL assign_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL assign_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL sort(AMX* amx, cell* params);
	/* Global */
	static cell AMX_NATIVE_CALL global(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_push_back(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_push_back_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_push_back_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_push_front(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_push_front_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_push_front_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_pop_back(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_pop_front(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_type(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_clear(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_size(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_empty(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_resize(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_remove(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_swap(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_swap_index(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_shrink_to_fit(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_is_exists(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_is_vector_exists(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_reverse(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_find(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_find_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_find_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_set(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_set_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_set_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_assign(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_assign_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_assign_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_sort(AMX* amx, cell* params);
	
	/* SDK */
	static int sdk_is_vector_exists(AMX* amx,unsigned pawnvec);
	static int sdk_is_exists(AMX* amx,int pawnvec, int elem);
	static void Unload(AMX* amx);
};
