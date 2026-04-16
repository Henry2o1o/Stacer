#include "format_util.h"

#include <QString>

QString FormatUtil::formatBytes(const quint64 &bytes)
{
#define formatUnit(v, u, t) QString().asprintf("%.1f %s", ((double)v / (double)u), t)
    if (bytes == 1L) // bytes
        return QString("%1 Byte").arg(bytes);
    else if (bytes < KIBI) // bytes
        return QString("%1 Byte").arg(bytes);
    else if (bytes < MEBI) // KiB
        return formatUnit(bytes, KIBI, "KB");
    else if (bytes < GIBI) // MiB
        return formatUnit(bytes, MEBI, "MB");
    else if (bytes < TEBI) // GiB
        return formatUnit(bytes, GIBI, "GB");
    else // TiBE
        return formatUnit(bytes, TEBI, "TB");
#undef formatUnit
}
