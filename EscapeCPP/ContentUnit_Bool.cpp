#include"ContentUnit_Bool.h"
#include"GameManager.h"

std::string error_bool_not_found = "can't find the following bool in  blackboard: ";

Content ContentUnit_Bool::get_content()
{
	int value = GameManager::Instance()->get_bool(bool_name);
	if (value < 0)
		return Content(error_bool_not_found + bool_name);
	return value > 0 ? content_true : content_false;
}