#include "SDK/plugin.h"

#include "CVectorNatives.h"
#include "CDequeNatives.h"
#include "CMapNatives.h"
#include "CMultiMapNatives.h"

typedef void (*logprintf_t)(char* format, ...);


logprintf_t logprintf;
extern void *pAMXFunctions;


PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() 
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) 
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t) ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf("-------------------------------------------------------");
	logprintf("-													 -");
	logprintf("-		Vectoral Pawn v1.0 Loaded					 -");
	logprintf("-				by Skyline.							 -");
	logprintf("-													 -");
	logprintf("-------------------------------------------------------");
    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    logprintf("-------------------------------------------------------");
	logprintf("-									                 -");
	logprintf("-	      Vectoral Pawn v1.0 Unloaded                -");
	logprintf("-				by Skyline.			                 -");
	logprintf("-									                 -");
	logprintf("-------------------------------------------------------");
}

AMX_NATIVE_INFO PluginNatives[] =
{
	/* Vector Natives */
	{"cvector", CVectorNatives::vector},
	{"cvector_push_back", CVectorNatives::push_back},
	{"cvector_push_back_arr", CVectorNatives::push_back_arr},
	{"cvector_push_back_float", CVectorNatives::push_back_float},
	{"cvector_push_front", CVectorNatives::push_front},
	{"cvector_push_front_arr", CVectorNatives::push_front_arr},
	{"cvector_push_front_float", CVectorNatives::push_front_float},
	{"cvector_get_type",CVectorNatives::get_type},
	{"cvector_pop_back",CVectorNatives::pop_back},
	{"cvector_pop_front",CVectorNatives::pop_front},
	{"cvector_clear",CVectorNatives::clear},
	{"cvector_size",CVectorNatives::size},
	{"cvector_capacity",CVectorNatives::capacity},
	{"cvector_empty",CVectorNatives::empty},
	{"cvector_resize",CVectorNatives::resize},
	{"cvector_remove",CVectorNatives::remove},
	{"cvector_swap_vector",CVectorNatives::swap},
	{"cvector_shrink_to_fit",CVectorNatives::shrink_to_fit},
	{"cvector_swap",CVectorNatives::swap_index},
	{"cvector_get",CVectorNatives::get},
	{"cvector_get_float",CVectorNatives::get_float},
	{"cvector_get_arr",CVectorNatives::get_arr},
	{"cvector_is_exists",CVectorNatives::is_exists},
	{"cvector_is_vector_exists",CVectorNatives::is_vector_exists},
	{"cvector_reverse",CVectorNatives::reverse},
	{"cvector_find",CVectorNatives::find},
	{"cvector_find_float",CVectorNatives::find_float},
	{"cvector_find_arr",CVectorNatives::find_arr},
	{"cvector_set",CVectorNatives::set},
	{"cvector_set_float",CVectorNatives::set_float},
	{"cvector_set_arr",CVectorNatives::set_arr},
	{"cvector_reserve",CVectorNatives::reserve},
	{"cvector_assign",CVectorNatives::assign},
	{"cvector_assign_arr",CVectorNatives::assign_arr},
	{"cvector_assign_float",CVectorNatives::assign_float},
	{"cvector_sort",CVectorNatives::sort},
	/* Global */
	{"cvector_g",CVectorNatives::global},
	{"cvector_g_push_back",CVectorNatives::g_push_back},
	{"cvector_g_push_back_arr",CVectorNatives::g_push_back_arr},
	{"cvector_g_push_back_float",CVectorNatives::g_push_back_float},
	{"cvector_g_push_front",CVectorNatives::g_push_front},
	{"cvector_g_push_front_arr",CVectorNatives::g_push_front_arr},
	{"cvector_g_push_front_float",CVectorNatives::g_push_front_float},
	{"cvector_g_get_type",CVectorNatives::g_get_type},
	{"cvector_g_pop_back",CVectorNatives::g_pop_back},
	{"cvector_g_pop_front",CVectorNatives::g_pop_front},
	{"cvector_g_clear",CVectorNatives::g_clear},
	{"cvector_g_size",CVectorNatives::g_size},
	{"cvector_g_capacity",CVectorNatives::g_capacity},
	{"cvector_g_empty",CVectorNatives::g_empty},
	{"cvector_g_resize",CVectorNatives::g_resize},
	{"cvector_g_remove",CVectorNatives::g_remove},
	{"cvector_g_swap_vector",CVectorNatives::g_swap},
	{"cvector_g_shrink_to_fit",CVectorNatives::g_shrink_to_fit},
	{"cvector_g_swap",CVectorNatives::g_swap_index},
	{"cvector_g_get",CVectorNatives::g_get},
	{"cvector_g_get_float",CVectorNatives::g_get_float},
	{"cvector_g_get_arr",CVectorNatives::g_get_arr},
	{"cvector_g_is_exists",CVectorNatives::g_is_exists},
	{"cvector_g_is_vector_exists",CVectorNatives::g_is_vector_exists},
	{"cvector_g_reverse",CVectorNatives::g_reverse},
	{"cvector_g_find",CVectorNatives::g_find},
	{"cvector_g_find_float",CVectorNatives::g_find_float},
	{"cvector_g_find_arr",CVectorNatives::g_find_arr},
	{"cvector_g_set",CVectorNatives::g_set},
	{"cvector_g_set_float",CVectorNatives::g_set_float},
	{"cvector_g_set_arr",CVectorNatives::g_set_arr},
	{"cvector_g_reserve",CVectorNatives::g_reserve},
	{"cvector_g_assign",CVectorNatives::g_assign},
	{"cvector_g_assign_arr",CVectorNatives::g_assign_arr},
	{"cvector_g_assign_arr_float",CVectorNatives::g_assign_float},
	{"cvector_g_sort",CVectorNatives::sort},
	/* Deque natives */
	{"cdeque",CDequeNatives::deque},
	{"cdeque_push_back",CDequeNatives::push_back},
	{"cdeque_push_back_arr",CDequeNatives::push_back_arr},
	{"cdeque_push_back_float",CDequeNatives::push_back_float},
	{"cdeque_push_front",CDequeNatives::push_front},
	{"cdeque_push_front_arr",CDequeNatives::push_front_arr},
	{"cdeque_push_front_float",CDequeNatives::push_front_float},
	{"cdeque_get_type",CDequeNatives::get_type},
	{"cdeque_pop_back",CDequeNatives::pop_back},
	{"cdeque_pop_front",CDequeNatives::pop_front},
	{"cdeque_clear",CDequeNatives::clear},
	{"cdeque_size",CDequeNatives::size},
	{"cdeque_empty",CDequeNatives::empty},
	{"cdeque_resize",CDequeNatives::resize},
	{"cdeque_remove",CDequeNatives::remove},
	{"cdeque_swap_deque",CDequeNatives::swap},
	{"cdeque_shrink_to_fit",CDequeNatives::shrink_to_fit},
	{"cdeque_swap",CDequeNatives::swap_index},
	{"cdeque_get",CDequeNatives::get},
	{"cdeque_get_float",CDequeNatives::get_float},
	{"cdeque_get_arr",CDequeNatives::get_arr},
	{"cdeque_is_exists",CDequeNatives::is_exists},
	{"cdeque_is_deque_exists",CDequeNatives::is_vector_exists},
	{"cdeque_reverse",CDequeNatives::reverse},
	{"cdeque_find",CDequeNatives::find},
	{"cdeque_find_float",CDequeNatives::find_float},
	{"cdeque_find_arr",CDequeNatives::find_arr},
	{"cdeque_set",CDequeNatives::set},
	{"cdeque_set_float",CDequeNatives::set_float},
	{"cdeque_set_arr",CDequeNatives::set_arr},
	{"cdeque_assign",CDequeNatives::assign},
	{"cdeque_assign_arr",CDequeNatives::assign_arr},
	{"cdeque_assign_float",CDequeNatives::assign_float},
	{"cdeque_sort",CDequeNatives::sort},
	/* Global */
	{"cdeque_g",CDequeNatives::global},
	{"cdeque_g_push_back",CDequeNatives::g_push_back},
	{"cdeque_g_push_back_arr",CDequeNatives::g_push_back_arr},
	{"cdeque_g_push_back_float",CDequeNatives::g_push_back_float},
	{"cdeque_g_push_front",CDequeNatives::g_push_front},
	{"cdeque_g_push_front_arr",CDequeNatives::g_push_front_arr},
	{"cdeque_g_push_front_float",CDequeNatives::g_push_front_float},
	{"cdeque_g_get_type",CDequeNatives::g_get_type},
	{"cdeque_g_pop_back",CDequeNatives::g_pop_back},
	{"cdeque_g_pop_front",CDequeNatives::g_pop_front},
	{"cdeque_g_clear",CDequeNatives::g_clear},
	{"cdeque_g_size",CDequeNatives::g_size},
	{"cdeque_g_empty",CDequeNatives::g_empty},
	{"cdeque_g_resize",CDequeNatives::g_size},
	{"cdeque_g_remove",CDequeNatives::g_remove},
	{"cdeque_g_swap_deque",CDequeNatives::g_swap},
	{"cdeque_g_shrink_to_fit",CDequeNatives::g_shrink_to_fit},
	{"cdeque_g_swap",CDequeNatives::g_swap_index},
	{"cdeque_g_get",CDequeNatives::g_get},
	{"cdeque_g_get_float",CDequeNatives::g_get_float},
	{"cdeque_g_get_arr",CDequeNatives::g_get_arr},
	{"cdeque_g_is_exists",CDequeNatives::g_is_exists},
	{"cdeque_g_is_deque_exists",CDequeNatives::g_is_vector_exists},
	{"cdeque_g_reverse",CDequeNatives::g_reverse},
	{"cdeque_g_find",CDequeNatives::g_find},
	{"cdeque_g_find_float",CDequeNatives::g_find_float},
	{"cdeque_g_find_arr",CDequeNatives::g_find_arr},
	{"cdeque_g_set",CDequeNatives::g_set},
	{"cdeque_g_set_float",CDequeNatives::g_set_float},
	{"cdeque_g_set_arr",CDequeNatives::g_set_arr},
	{"cdeque_g_assign",CDequeNatives::g_assign},
	{"cdeque_g_assign_arr",CDequeNatives::g_assign_arr},
	{"cdeque_g_assign_float",CDequeNatives::g_assign_float},
	{"cdeque_g_sort",CDequeNatives::g_sort},
	/* Map Natives */
	{"cmap",CMapNatives::l_map},

	{"cmap_insert",CMapNatives::insert},
	{"cmap_insert_arr",CMapNatives::insert_arr},
	{"cmap_insert_float",CMapNatives::insert_float},

	{"cmap_insert_key_int",CMapNatives::insert_key_int},
	{"cmap_insert_key_int_arr",CMapNatives::insert_key_int_arr},
	{"cmap_insert_key_int_float",CMapNatives::insert_key_int_float},
	
	{"cmap_insert_key_float",CMapNatives::insert_key_float},
	{"cmap_insert_key_float_arr",CMapNatives::insert_key_float_arr},
	{"cmap_insert_key_float_float",CMapNatives::insert_key_float_float},

	{"cmap_get",CMapNatives::get},
	{"cmap_get_arr",CMapNatives::get_arr},
	{"cmap_get_float",CMapNatives::get_float},

	{"cmap_get_key_int",CMapNatives::get_key_int},
	{"cmap_get_key_int_arr",CMapNatives::get_key_int_arr},
	{"cmap_get_key_int_float",CMapNatives::get_key_int_float},

	{"cmap_get_key_float",CMapNatives::get_key_float},
	{"cmap_get_key_float_arr",CMapNatives::get_key_float_arr},
	{"cmap_get_key_float_float",CMapNatives::get_key_float_float},

	{"cmap_contains",CMapNatives::contains},
	{"cmap_contains_int",CMapNatives::contains_int},
	{"cmap_contains_float",CMapNatives::contains_float},

	{"cmap_get_type",CMapNatives::get_type},
	{"cmap_get_type_int",CMapNatives::get_type_int},
	{"cmap_get_type_float",CMapNatives::get_type_float},

	{"cmap_clear",CMapNatives::clear},
	{"cmap_size",CMapNatives::size},

	{"cmap_remove",CMapNatives::remove},
	{"cmap_remove_int",CMapNatives::remove_int},
	{"cmap_remove_float",CMapNatives::remove_float},

	{"cmap_swap_map",CMapNatives::swap},

	{"cmap_swap",CMapNatives::swap_key},
	{"cmap_swap_int",CMapNatives::swap_int},
	{"cmap_swap_float",CMapNatives::swap_float},

	{"cmap_swap_key_int",CMapNatives::swap_key_int},
	{"cmap_swap_key_int_float",CMapNatives::swap_key_int_float},
	{"cmap_swap_key_int_arr",CMapNatives::swap_key_int_arr},

	{"cmap_swap_key_float",CMapNatives::swap_key_float},
	{"cmap_swap_key_float_int",CMapNatives::swap_key_float_int},
	{"cmap_swap_key_float_arr",CMapNatives::swap_key_float_arr},

	{"cmap_empty",CMapNatives::empty},
	/* Global */
	{"cmap_g",CMapNatives::g_map},

	{"cmap_g_insert",CMapNatives::insert},
	{"cmap_g_insert_arr",CMapNatives::insert_arr},
	{"cmap_g_insert_float",CMapNatives::insert_float},

	{"cmap_g_insert_key_int",CMapNatives::insert_key_int},
	{"cmap_g_insert_key_int_arr",CMapNatives::insert_key_int_arr},
	{"cmap_g_insert_key_int_float",CMapNatives::insert_key_int_float},

	{"cmap_g_insert_key_float",CMapNatives::insert_key_float},
	{"cmap_g_insert_key_float_arr",CMapNatives::insert_key_float_arr},
	{"cmap_g_insert_key_float_float",CMapNatives::insert_key_float_float},

	{"cmap_g_get",CMapNatives::get},
	{"cmap_g_get_arr",CMapNatives::get_arr},
	{"cmap_g_get_float",CMapNatives::get_float},

	{"cmap_g_get_key_int",CMapNatives::get_key_int},
	{"cmap_g_get_key_int_arr",CMapNatives::get_key_int_arr},
	{"cmap_g_get_key_int_float",CMapNatives::get_key_int_float},

	{"cmap_g_get_key_float",CMapNatives::get_key_float},
	{"cmap_g_get_key_float_arr",CMapNatives::get_key_float_arr},
	{"cmap_g_get_key_float_float",CMapNatives::get_key_float_float},

	{"cmap_g_contains",CMapNatives::contains},
	{"cmap_g_contains_int",CMapNatives::contains_int},
	{"cmap_g_contains_float",CMapNatives::contains_float},

	{"cmap_g_get_type",CMapNatives::get_type},
	{"cmap_g_get_type_int",CMapNatives::get_type_int},
	{"cmap_g_get_type_float",CMapNatives::get_type_float},

	{"cmap_g_clear",CMapNatives::clear},
	{"cmap_g_size",CMapNatives::size},

	{"cmap_g_remove",CMapNatives::remove},
	{"cmap_g_remove_int",CMapNatives::remove_int},
	{"cmap_g_remove_float",CMapNatives::remove_float},

	{"cmap_g_swap_map",CMapNatives::swap},

	{"cmap_g_swap",CMapNatives::swap_key},
	{"cmap_g_swap_int",CMapNatives::swap_int},
	{"cmap_g_swap_float",CMapNatives::swap_float},

	{"cmap_g_swap_key_int",CMapNatives::swap_key_int},
	{"cmap_g_swap_key_int_float",CMapNatives::swap_key_int_float},
	{"cmap_g_swap_key_int_arr",CMapNatives::swap_key_int_arr},

	{"cmap_g_swap_key_float",CMapNatives::swap_key_float},
	{"cmap_g_swap_key_float_int",CMapNatives::swap_key_float_int},
	{"cmap_g_swap_key_float_arr",CMapNatives::swap_key_float_arr},

	{"cmap_g_empty",CMapNatives::empty},
	/* Multimap Natives */
	{"cmmap",CMultiMapNatives::l_multimap},

	{"cmmap_insert",CMultiMapNatives::insert},
	{"cmmap_insert_arr",CMultiMapNatives::insert_arr},
	{"cmmap_insert_float",CMultiMapNatives::insert_float},

	{"cmmap_insert_key_int",CMultiMapNatives::insert_key_int},
	{"cmmap_insert_key_int_arr",CMultiMapNatives::insert_key_int_arr},
	{"cmmap_insert_key_int_float",CMultiMapNatives::insert_key_int_float},
	
	{"cmmap_insert_key_float",CMultiMapNatives::insert_key_float},
	{"cmmap_insert_key_float_arr",CMultiMapNatives::insert_key_float_arr},
	{"cmmap_insert_key_float_float",CMultiMapNatives::insert_key_float_float},

	{"cmmap_get",CMultiMapNatives::get},
	{"cmmap_get_arr",CMultiMapNatives::get_arr},
	{"cmmap_get_float",CMultiMapNatives::get_float},

	{"cmmap_get_key_int",CMultiMapNatives::get_key_int},
	{"cmmap_get_key_int_arr",CMultiMapNatives::get_key_int_arr},
	{"cmmap_get_key_int_float",CMultiMapNatives::get_key_int_float},

	{"cmmap_get_key_float",CMultiMapNatives::get_key_float},
	{"cmmap_get_key_float_arr",CMultiMapNatives::get_key_float_arr},
	{"cmmap_get_key_float_float",CMultiMapNatives::get_key_float_float},

	{"cmmap_contains",CMultiMapNatives::contains},
	{"cmmap_contains_int",CMultiMapNatives::contains_int},
	{"cmmap_contains_float",CMultiMapNatives::contains_float},

	{"cmmap_get_type",CMultiMapNatives::get_type},
	{"cmmap_get_type_int",CMultiMapNatives::get_type_int},
	{"cmmap_get_type_float",CMultiMapNatives::get_type_float},

	{"cmmap_clear",CMultiMapNatives::clear},
	{"cmmap_size",CMultiMapNatives::size},

	{"cmmap_remove",CMultiMapNatives::remove},
	{"cmmap_remove_int",CMultiMapNatives::remove_int},
	{"cmmap_remove_float",CMultiMapNatives::remove_float},

	{"cmmap_swap_map",CMultiMapNatives::swap},	
	{"cmmap_empty",CMultiMapNatives::empty},

	{"cmmap_count",CMultiMapNatives::count},
	{"cmmap_count_float",CMultiMapNatives::count_float},
	{"cmmap_count_int",CMultiMapNatives::count_int},

	{"cmmap_set",CMultiMapNatives::set},
	{"cmmap_set_arr",CMultiMapNatives::set_arr},
	{"cmmap_set_float",CMultiMapNatives::set_float},

	{"cmmap_set_key_int",CMultiMapNatives::set_key_int},
	{"cmmap_set_key_int_arr",CMultiMapNatives::set_key_int_arr},
	{"cmmap_set_key_int_float",CMultiMapNatives::set_key_int_float},

	{"cmmap_set_key_float",CMultiMapNatives::set_key_float},
	{"cmmap_set_key_float_arr",CMultiMapNatives::set_key_float_arr},
	{"cmmap_set_key_float_float",CMultiMapNatives::set_key_float_float},
	/* GLOBAL */
	{"cmmap_g",CMultiMapNatives::g_multimap},

	{"cmmap_g_insert",CMultiMapNatives::g_insert},
	{"cmmap_g_insert_arr",CMultiMapNatives::g_insert_arr},
	{"cmmap_g_insert_float",CMultiMapNatives::g_insert_float},

	{"cmmap_g_insert_key_int",CMultiMapNatives::g_insert_key_int},
	{"cmmap_g_insert_key_int_arr",CMultiMapNatives::g_insert_key_int_arr},
	{"cmmap_g_insert_key_int_float",CMultiMapNatives::g_insert_key_int_float},
	
	{"cmmap_g_insert_key_float",CMultiMapNatives::g_insert_key_float},
	{"cmmap_g_insert_key_float_arr",CMultiMapNatives::g_insert_key_float_arr},
	{"cmmap_g_insert_key_float_float",CMultiMapNatives::g_insert_key_float_float},

	{"cmmap_g_get",CMultiMapNatives::g_get},
	{"cmmap_g_get_arr",CMultiMapNatives::g_get_arr},
	{"cmmap_g_get_float",CMultiMapNatives::g_get_float},

	{"cmmap_g_get_key_int",CMultiMapNatives::g_get_key_int},
	{"cmmap_g_get_key_int_arr",CMultiMapNatives::g_get_key_int_arr},
	{"cmmap_g_get_key_int_float",CMultiMapNatives::g_get_key_int_float},

	{"cmmap_g_get_key_float",CMultiMapNatives::g_get_key_float},
	{"cmmap_g_get_key_float_arr",CMultiMapNatives::g_get_key_float_arr},
	{"cmmap_g_get_key_float_float",CMultiMapNatives::g_get_key_float_float},

	{"cmmap_g_contains",CMultiMapNatives::g_contains},
	{"cmmap_g_contains_int",CMultiMapNatives::g_contains_int},
	{"cmmap_g_contains_float",CMultiMapNatives::g_contains_float},

	{"cmmap_g_get_type",CMultiMapNatives::g_get_type},
	{"cmmap_g_get_type_int",CMultiMapNatives::g_get_type_int},
	{"cmmap_g_get_type_float",CMultiMapNatives::g_get_type_float},

	{"cmmap_g_clear",CMultiMapNatives::g_clear},
	{"cmmap_g_size",CMultiMapNatives::g_size},

	{"cmmap_g_remove",CMultiMapNatives::g_remove},
	{"cmmap_g_remove_int",CMultiMapNatives::g_remove_int},
	{"cmmap_g_remove_float",CMultiMapNatives::g_remove_float},

	{"cmmap_g_swap_map",CMultiMapNatives::g_swap},	
	{"cmmap_g_empty",CMultiMapNatives::g_empty},

	{"cmmap_g_count",CMultiMapNatives::g_count},
	{"cmmap_g_count_float",CMultiMapNatives::g_count_float},
	{"cmmap_g_count_int",CMultiMapNatives::g_count_int},

	{"cmmap_g_set",CMultiMapNatives::g_set},
	{"cmmap_g_set_arr",CMultiMapNatives::g_set_arr},
	{"cmmap_g_set_float",CMultiMapNatives::g_set_float},

	{"cmmap_g_set_key_int",CMultiMapNatives::g_set_key_int},
	{"cmmap_g_set_key_int_arr",CMultiMapNatives::g_set_key_int_arr},
	{"cmmap_g_set_key_int_float",CMultiMapNatives::g_set_key_int_float},

	{"cmmap_g_set_key_float",CMultiMapNatives::g_set_key_float},
	{"cmmap_g_set_key_float_arr",CMultiMapNatives::g_set_key_float_arr},
	{"cmmap_g_set_key_float_float",CMultiMapNatives::g_set_key_float_float},
    {0, 0}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad( AMX *amx ) 
{
    return amx_Register(amx, PluginNatives, -1);
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload( AMX *amx ) 
{
	/*for(vector<VectorStruct>::iterator it=all_vectors.begin(); it!=all_vectors.end(); ++it){
		if ((*it).amx == amx){
			(*it).vector.clear();
			all_vectors.erase(it);
		}
	}*/
	CVectorNatives::Unload(amx);
	CDequeNatives::Unload(amx);
	CMapNatives::Unload(amx);
	CMultiMapNatives::Unload(amx);
    return AMX_ERR_NONE;
}
