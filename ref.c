#include "common/err.h"
#include "api/ref.h"
#include "api/util.h"

UwUVMValue uwu_call(UwUVMArgs *args)
{
	uwuutil_require_min("ref.call", args, 1);

	UwUVMValue value = uwuvm_get_arg(args, 0);

	if (value.type != &uwuref_type)
		error("ref.call requires a function reference as $1\n");

	return uwuvm_call_function(value.data, args->num - 1, &args->unevaluated[1], args->super);
}

UwUVMValue uwu_is(UwUVMArgs *args)
{
	return uwuutil_is_type("ref.is", args, &uwuref_type);
}
