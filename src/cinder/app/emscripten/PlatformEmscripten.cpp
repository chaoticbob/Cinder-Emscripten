/*
 Copyright (c) 2012, The Cinder Project, All rights reserved.

 This code is intended for use with the Cinder C++ library: http://libcinder.org

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

#include "cinder/app/emscripten/PlatformEmscripten.h"
#include "cinder/ImageSourceFileRadiance.h"
#include "cinder/ImageSourceFileStbImage.h"
#include "cinder/ImageTargetFileStbImage.h"

#include <unistd.h>
#include <limits.h>

namespace cinder {

extern void FontManager_destroyStaticInstance();

} // namespace cinder

namespace cinder { namespace app {

namespace {

const size_t RESOURCE_SEARCH_DEPTH = 10;

} // anonymous namespace

PlatformEmscripten::PlatformEmscripten()
{
	ImageSourceFileRadiance::registerSelf();
	ImageSourceFileStbImage::registerSelf();
	ImageTargetFileStbImage::registerSelf();
}

PlatformEmscripten::~PlatformEmscripten()
{
}

PlatformEmscripten* PlatformEmscripten::get() 
{ 
	return reinterpret_cast<PlatformEmscripten*>( Platform::get() ); 
}

void PlatformEmscripten::cleanupLaunch()
{
	cinder::FontManager_destroyStaticInstance();
}

DataSourceRef PlatformEmscripten::loadResource( const fs::path &resourcePath ) 
{
	fs::path fullPath = getResourcePath( resourcePath );

	// On Emscripten we can't go beyond the root of the virtual fs. Walk the
	// path towards the basename in hopes we find something.
	if( fullPath.empty() ) {
		std::vector<fs::path> parts;
		for( const auto& part : resourcePath ) {			
			parts.push_back( part );
		}

		for( auto outerIter = parts.begin(); outerIter != parts.end(); ++outerIter ) {
			auto innerIter = outerIter;

			fs::path path;
			for( ; innerIter != parts.end(); ++innerIter ) {
				if( ! path.empty() ) {
					path /= *innerIter;
				}
				else {
					path = *innerIter;
				}
			}

			fullPath = getResourcePath( path );
			if( ! fullPath.empty() ) {
				break;
			}
		}
	}

	if( fullPath.empty() )
		throw ResourceLoadExc( std::string( "Could not resolve absolute path for: " ) + resourcePath.string() );
	else 
		return DataSourcePath::create( fullPath );	
}

fs::path PlatformEmscripten::getResourceDirectory() const 
{
	// @TODO: Implement
	return fs::path();	
}

fs::path PlatformEmscripten::getResourcePath( const fs::path &rsrcRelativePath ) const
{
	if( ! mResourceDirsInitialized ) {
		mResourceDirsInitialized = true;
		mResourceDirectories.push_back( "/" );
	}

	for( const auto &directory : mResourceDirectories ) {
		auto fullPath = directory / rsrcRelativePath;
		if( fs::exists( fullPath ) )
			return fullPath;
	}

	return fs::path(); // empty implies failure	
}


fs::path PlatformEmscripten::getOpenFilePath( const fs::path &initialPath, const std::vector<std::string> &extensions ) 
{
	// @TODO: Implement
	return fs::path();
}

fs::path PlatformEmscripten::getFolderPath( const fs::path &initialPath ) 
{
	// @TODO: Implement
	return fs::path();
}

fs::path PlatformEmscripten::getSaveFilePath( const fs::path &initialPath, const std::vector<std::string> &extensions ) 
{
	// @TODO: Implement
	return fs::path();
}

std::map<std::string, std::string> PlatformEmscripten::getEnvironmentVariables() 
{
	// @TODO: Implement
	return std::map<std::string, std::string>();
}

fs::path PlatformEmscripten::expandPath( const fs::path &path ) 
{
	// @TODO: Implement
	return fs::path();	
}

fs::path PlatformEmscripten::getHomeDirectory() const 
{
	// @TODO: Implement
	return fs::path();	
}

fs::path PlatformEmscripten::getDocumentsDirectory() const 
{
	// @TODO: Implement
	return fs::path();	
}

fs::path PlatformEmscripten::getDefaultExecutablePath() const 
{
	std::vector<char> buf( PATH_MAX );
	std::memset( &(buf[0]), 0, buf.size()  );
    ssize_t len = ::readlink("/proc/self/exe", &(buf[0]), buf.size() - 1 );
    if( ( -1 != len ) && ( len < buf.size() ) ) {
      buf[len] = '\0';
    }
 	return fs::path( std::string( &(buf[0]), len ) );
}

void PlatformEmscripten::sleep( float milliseconds ) 
{
	// @TODO: Implement
}

void PlatformEmscripten::launchWebBrowser( const Url &url ) 
{
	// @TODO: Implement
}

std::vector<std::string> PlatformEmscripten::stackTrace() 
{
	// @TODO: Implement
	return std::vector<std::string>();	
}

const std::vector<DisplayRef>& PlatformEmscripten::getDisplays()
{
	if( ! mDisplaysInitialized ) {
		// @TODO: Implement fuller

		mDisplaysInitialized = true;
	}

	return mDisplays;
}

}} // namespace cinder::app
