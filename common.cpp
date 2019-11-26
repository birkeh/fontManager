#include "common.h"


QString	color2rgba(const QColor& color)
{
	return(QString("rgba(%1, %2, %3, %4)").arg(color.red()).arg(color.green()).arg(color.blue()).arg(255));
}
