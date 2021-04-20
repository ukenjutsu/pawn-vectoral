#include <vector>
#include <map>
#include <string>
using namespace std;
class CMapNatives{
public:
	static cell AMX_NATIVE_CALL l_map(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL insert(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL insert_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL insert_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL insert_key_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL insert_key_int_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL insert_key_int_float(AMX* amx, cell* params);
	
	static cell AMX_NATIVE_CALL insert_key_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL insert_key_float_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL insert_key_float_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL get(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL get_key_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_key_int_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_key_int_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL get_key_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_key_float_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_key_float_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL contains(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL contains_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL contains_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL get_type(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_type_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL get_type_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL clear(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL size(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL remove(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL remove_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL remove_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL swap(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL empty(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL swap_key(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL swap_int(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL swap_float(AMX* amx, cell* params);	
	
	static cell AMX_NATIVE_CALL swap_key_int(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL swap_key_int_float(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL swap_key_int_arr(AMX* amx, cell* params);	

	static cell AMX_NATIVE_CALL swap_key_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL swap_key_float_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL swap_key_float_int(AMX* amx, cell* params);


	/* Global */
	static cell AMX_NATIVE_CALL g_map(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_insert(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_insert_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_insert_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_insert_key_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_insert_key_int_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_insert_key_int_float(AMX* amx, cell* params);
	
	static cell AMX_NATIVE_CALL g_insert_key_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_insert_key_float_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_insert_key_float_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_get(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_get_key_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_key_int_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_key_int_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_get_key_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_key_float_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_key_float_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_contains(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_contains_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_contains_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_get_type(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_type_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_get_type_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_clear(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_size(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_remove(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_remove_int(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_remove_float(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_swap(AMX* amx, cell* params);	

	static cell AMX_NATIVE_CALL g_swap_key(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL g_swap_int(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL g_swap_float(AMX* amx, cell* params);	
	
	static cell AMX_NATIVE_CALL g_swap_key_int(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL g_swap_key_int_float(AMX* amx, cell* params);	
	static cell AMX_NATIVE_CALL g_swap_key_int_arr(AMX* amx, cell* params);	

	static cell AMX_NATIVE_CALL g_swap_key_float(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_swap_key_float_arr(AMX* amx, cell* params);
	static cell AMX_NATIVE_CALL g_swap_key_float_int(AMX* amx, cell* params);

	static cell AMX_NATIVE_CALL g_empty(AMX* amx, cell* params);	

	/* SDK */
	static int sdk_is_map_exists(AMX* amx,unsigned pawnvec);
	static int sdk_is_exists(AMX* amx,int pawnvec, void* elem);
	static void Unload(AMX* amx);
};