gm_io
---
Unlimited Garry's Mod file access!

###Credits
	Me - For some of the code
	Endless ammounts of c++ tutorials - For the rest of the code
	Garry Newman - For Garry's Mod and Bootil

###Release

#####Linux
* Client - [gmcl_io_linux.so](http://www.google.com)
* Server - [gmsv_io_linux.so](http://www.google.com)

#####Windows
* Client - [gmcl_io_win32.dll](http://www.google.com)
* Server - [gmsv_io_win32.dll](http://www.google.com)

###Reference

####io.file
```lua
--[[
  Finds files and folders from a search path.

  @param  string  search  Search path
  @return table           Files
  @return table           Folders
  @return number          Item count
]]
io.file.Find(search)

--[[
  Checks to see if a file exists.

  @param  string  path  ...
  @return bool          ...
]]
io.file.Exists(path)

--[[
  Gets all files in a folder.

  @param  string  path      Folder path
  @param  bool    recursive Recursive folder check
  @return table             Files
  @return number            Item count
]]
io.file.GetFilesInFolder(path recursive = false)

--[[
  Get file size.

  @param  string  path  File path
  @return number        File size
]]
io.file.Size(path)

--[[
  Get file contents.

  @param  string  path  File path
  @return string        File contents
]]
io.file.Read(path)

--[[
  Set file contents.

  @param  string  path  File path
  @param  string  data  File data
  @return bool          Success
]]
io.file.Write(path, data)

--[[
  Append file contents.

  @param  string  path  File path
  @param  string  data  File data
  @return bool          Success
]]
io.file.Append(path, data)

--[[
  Copy file from one location to another.

  @param  string  path_from Initial path
  @param  string  path_to   Destination path
  @return bool              Success
]]
io.file.Copy(path_from, path_to)

--[[
  Move file from one location to another.

  @param  string  path_from Initial path
  @param  string  path_to   Destination path
  @return bool              Success
]]
io.file.Move(path_from, path_to)

--[[
  Remove file.

  @param  string  path  File path
  @return bool          Success
]]
io.file.Remove(path)

--[[
  Get temporary file directory.

  @return string  Temporary directory path
]]
io.file.GetTempDir()

--[[
  Get generated temporary file path.

  @return string  Temporary file path
]]
io.file.GetTempFilename()
```

####io.directory
```lua
--[[
	Checks to see if a directory exists.

	@param	string	path 	Directory path
	@return	bool			Exists
]]
io.directory.Exists(path)

--[[
	Creates a directory.

	@param	string	path		Directory path
	@param	bool	recursive	Recursive directory creation
	@return bool				Success
]]
io.directory.Create(path recursive = false)

--[[
	Removes a directory.

	@param	string	path	Directory path
	@return bool			Success
]]
io.directory.Remove()
```

####io.watcher (unsure if this works yet)
```lua
--[[
	Adds a folder watcher.

	@param	string		name			Watcher identifier
	@param	string		path			Directory path
	@param	function	callback		Change callback
	@param	bool		watch_subtree	Watch child folders
	@return bool						Success
]]
io.watcher.Add(name, path, callback, watch_subtree = false)

--[[
	Stops a folder watcher.

	@param	string	name	Watcher identifier
]]
io.watcher.Remove(name)
```