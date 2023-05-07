# thanks Piotr Siupa from stackoverflow

from SCons.Environment import Base as BaseEnvironment

def __RGlob(self, root_path, pattern, ondisk=True, source=False, strings=False, exclude=None):
    result_nodes = []
    paths = [root_path]
    while paths:
        path = paths.pop()
        all_nodes = self.Glob(f'{path}/*', ondisk=ondisk, source=source, exclude=exclude)
        paths.extend(entry for entry in all_nodes if entry.isdir() or (entry.srcnode() and entry.srcnode().isdir())) # `srcnode()` must be used because `isdir()` doesn't work for entries in variant dirs which haven't been copied yet.
        result_nodes.extend(self.Glob(f'{path}/{pattern}', ondisk=ondisk, source=source, strings=strings, exclude=exclude))
    return sorted(result_nodes)

def build_g4(path, flags):
    pass
BaseEnvironment.RGlob = __RGlob