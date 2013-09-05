#pragma once
#include <string>

class SKYENGINE_CORE_API ResIdentifier
{
public:
	ResIdentifier( std::string const & name, uint64_t timestamp, std::istream* const & is )
		: res_name_(name), time_stamp_(timestamp), istream_(is)
	{
	}

	void ResName(std::string const & name){
		res_name_ = name;
	}

	std::string const & ResName() const {
		return res_name_;
	}

	void TimeStamp( uint64_t ts ){
		time_stamp_ = ts;
	}

	uint64_t TimeStamp() const {
		return time_stamp_;
	}

	void read( void* p, size_t size ){
		istream_->read( static_cast<char*>(p), static_cast<std::streamsize>(size) );
	}

	int64_t gcount() const{
		return static_cast<int64_t>(istream_->gcount());
	}

	void seekg( int64_t offset, std::ios_base::seekdir way ){
		istream_->seekg( static_cast<std::istream::off_type>(offset), way );
	}

	int64_t tellg() const{
		return static_cast<int64_t>(istream_->tellg());
	}

	void clear(){
		istream_->clear();
	}

	std::istream* & input_stream(){
		return istream_;
	}
private:
	std::string res_name_;
	uint64_t	time_stamp_;
	std::istream* istream_;
};

class SKYENGINE_CORE_API ResLoader
{
public:
	static ResLoader& Instance();
	void AddPath( std::string const & path );
	std::string Locate( std::string const & name );

	ResIdentifierPtr Open( std::string const & name );
	void Close( ResIdentifierPtr rs );

private:
	ResLoader();

	std::string exe_path_;
	std::vector<std::string> paths_;
};