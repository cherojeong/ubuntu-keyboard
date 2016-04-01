// We have two blocks of utf-16 characters that can be used as emoji
var start = [[55356, 57088], [55357, 56320]];
var end = [[55356, 57335], [55357, 57301]];

// Not supported by any of the installed fonts, or not supported on Android or iOS
var skip = [[ 57121, 57122, 57123, 57124, 57125, 57126, 57127, 57128, 57129,
57130, 57131, 57132, 57133, 57134, 57135, 57142, 57213, 57214, 57215, 57235,
57236, 57237, 57238, 57239, 57240, 57241, 57242, 57243, 57244, 57245, 57246,
57247, 57285, 57291, 57292, 57293, 57294, 57295, 57296, 57297, 57298, 57299,
57300, 57301, 57302, 57303, 57304, 57305, 57306, 57307, 57308, 57309, 57310,
57311, 57329, 57330, 57331, 57332, 57333, 57334, 57335],
            [ 56383, 56468, 56573, 56574, 56575, 56598, 56638, 56639, 56640,
56641, 56642, 56643, 56644, 56645, 56646, 56647, 56648, 56649, 56650, 56651,
56652, 56653, 56654, 56655, 56675, 56680, 56681, 56682, 56683, 56684, 56685,
56686, 56687, 56688, 56689, 56690, 56691, 56692, 56693, 56694, 56695, 56696,
56697, 56698, 56699, 56700, 56701, 56702, 56703, 56704, 56705, 56706, 56707,
56708, 56709, 56710, 56711, 56712, 56713, 56714, 56715, 56716, 56717, 56718,
56719, 56720, 56721, 56722, 56723, 56724, 56725, 56726, 56727, 56728, 56729,
56730, 56731, 56732, 56733, 56734, 56735, 56736, 56737, 56738, 56739, 56740,
56741, 56742, 56743, 56744, 56745, 56746, 56747, 56748, 56749, 56750, 56751,
56752, 56753, 56754, 56755, 56756, 56757, 56758, 56759, 56760, 56761, 56762,
56763, 56764, 56765, 56766, 56767, 56768, 56769, 56770, 56771, 56772, 56773,
56774, 56775, 56776, 56777, 56778, 56779, 56780, 56781, 56782, 56783, 56784,
56785, 56786, 56787, 56788, 56789, 56790, 56791, 56792, 56793, 56794, 56795,
56796, 56797, 56798, 56799, 56800, 56801, 56802, 56803, 56804, 56805, 56806,
56807, 56808, 56809, 56810, 56811, 56812, 56813, 56814, 56815, 56816, 56817,
56818, 56819, 56820, 56821, 56822, 56823, 56824, 56825, 56826, 56884, 56897,
56898, 56899, 56900, 56912, 56913, 56914, 56915, 56916, 56917, 56918, 56919,
56920, 56921, 56922, 56923, 56924, 56925, 56926, 56927, 56928, 56929, 56930,
56931, 56932, 56933, 56934, 56935, 56936, 56937, 56938, 56939, 56940, 56941,
56942, 56943, 56944, 56945, 56946, 56947, 56948, 56949, 56950, 56951, 56952,
56953, 56954, 56955, 56956, 56957, 56958, 56959, 56698, 57030, 57031, 57032,
57033, 57034, 57035, 57036, 57037, 57038, 57039, 57040, 57041, 57042, 57043,
57044, 57045, 57046, 57047, 57048, 57049, 57050, 57051, 57052, 57053, 57054,
57055, 57056, 57057, 57058, 57059, 57060, 57061, 57062, 57063, 57064, 57065,
57066, 57067, 57068, 57069, 57070, 57071, 57072, 57073, 57074, 57075, 57076,
57077, 57078, 57079, 57080, 57081, 57082, 57083, 57084, 57085, 57086, 57087,
57088, 57089, 57090, 57091, 57092, 57093, 57094, 57095, 57096, 57097, 57098,
57099, 57100, 57101, 57102, 57103, 57104, 57105, 57106, 57107, 57108, 57109,
57110, 57111, 57112, 57113, 57114, 57115, 57116, 57117, 57118, 57119, 57120,
57121, 57122, 57123, 57124, 57125, 57126, 57127, 57128, 57129, 57130, 57131,
57132, 57133, 57134, 57135, 57136, 57137, 57138, 57139, 57140, 57141, 57142,
57143, 57144, 57145, 57146, 57147, 57148, 57149, 57150, 57151, 57152, 57153,
57154, 57155, 57156, 57157, 57158, 57159, 57160, 57161, 57162, 57163, 57164,
57165, 57166, 57167, 57168, 57169, 57170, 57171, 57172, 57173, 57174, 57175,
57176, 57177, 57178, 57179, 57180, 57181, 57182, 57183, 57184, 57185, 57186,
57187, 57188, 57189, 57190, 57191, 57192, 57193, 57194, 57195, 57196, 57197,
57198, 57199, 57200, 57201, 57202, 57203, 57204, 57205, 57206, 57207, 57208,
57209, 57210, 57211, 57212, 57213, 57214, 57215, 57216, 57217, 57218, 57219,
57220, 57221, 57222, 57223, 57224, 57225, 57226, 57227, 57228, 57229, 57230,
57231, 57232, 57233, 57234, 57235, 57236, 57237, 57238, 57239, 57240, 57241,
57242, 57243, 57244, 57245, 57246, 57247, 57248, 57249, 57250, 57251, 57252,
57253, 57254, 57255, 57256, 57257, 57258, 57259, 57260, 57261, 57262, 57263,
57264, 57265, 57266, 57267, 57268, 57269, 57270, 57271, 57272, 57273, 57274,
57275, 57276, 57277, 57278, 57279, 57280, 57281, 57282, 57283, 57284, 57285,
57286, 57287, 57288, 57289, 57290, 57291, 57292, 57293, 57294, 57295, 57296,
57297, 57298, 57299, 57300, 57301]];
