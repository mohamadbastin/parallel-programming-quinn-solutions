A copy machine’s feeder tray holds pages to be copied. Assume that it
takes 5 seconds to load a new group of pages into the feeder before
copying and 10 seconds to unload the originals and the copies after
copying. If the copier takes 4 seconds to print the first page of a group
and 1 second to print every subsequent page, what is the minimum
capacity of the feeder tray necessary to ensure that the effective
throughput of the copier asymptotically approaches 40 pages per minute
as the length of the original document increases?

---

well, if we want to have the minimum tray size, we then should maximize our load and unload operations.
each load takes 5 seconds. each unload takes 10 seconds. so each loading process takes 15 seconds.
if we have X pages, first page takes 4 seconds and others take 1. so it takes (X-1)+4 = X+3 seconds copying X pages.

so now we have ```T(x) = x + 18```.
according to this formula, if we want to have 40 pages copied in every minute, it takes 58 seconds or pretty much the hole minute.
so I would say that the minimum tray size should be 40.