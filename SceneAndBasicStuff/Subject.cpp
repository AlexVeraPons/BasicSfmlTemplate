#include "Subject.hpp"
#include <stdio.h>

void observer_concrete::notify(const int&)
{
	printf("observer_concrete::notify(const int&)");
}
