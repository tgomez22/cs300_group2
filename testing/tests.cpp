#include "catch.hpp"
#include "../data_structures/personList.h"
#include "../data_structures/serviceList.h"

TEST_CASE( "add a memId to entity" )
{
	entity anEntity;
    REQUIRE( anEntity.addId("100000000") == true );
}

TEST_CASE( "return correct array value for entity" )
{
    entity anEntity;
	anEntity.addId("100000000");
    REQUIRE( anEntity.getIdValue() == 433);
}

TEST_CASE( "succesfully add an entity to personList" )
{
    personList table;
    entity toAdd;
    toAdd.addId("100000000");
    REQUIRE( table.add(toAdd) == true );
}

TEST_CASE ( "remove an entity that exists in personList" )
{
	personList table;
	entity toAdd;
	toAdd.addId("100000000");
	table.add(toAdd);
	REQUIRE( table.removeMember(toAdd) == true );
}

TEST_CASE( "remove an entity that doesn't exist in personList" )
{
	personList table;	
	entity toAdd;
	toAdd.addId("100000000");
	REQUIRE( table.removeMember(toAdd) == false );
}

TEST_CASE( "get first index of member entity for auth" )
{
    entity aMember;
    aMember.addId("100000000");
    REQUIRE( aMember.getFirstIndex() == 1 );
	SECTION( "get first index of provider entity for auth" )
	{
		entity aProvider;
		aProvider.addId("200000000");
		REQUIRE( aProvider.getFirstIndex() == 2 );
	}
	SECTION( "get first index of manager entity for auth" )
	{
		entity aManager;
		aManager.addId("300000000");
		REQUIRE( aManager.getFirstIndex() == 3 );
	}
}

TEST_CASE( "check if a suspended member is suspended" )
{
    member aMember;
    aMember.addInfo("100000000", "John Doe", "246 Jefferson St", "Portland", "OR", "97201", true, 150.00);
    REQUIRE( aMember.isSuspended() == true );
	SECTION( "check if a non-suspended member is suspended" )
	{
		member aMember;
		aMember.addInfo("100000001", "Jane Doe", "246 Jefferson St", "Portland", "OR", "97201", false, 150.00);
		REQUIRE( aMember.isSuspended() == false );	
	}
}

TEST_CASE ( "check if a member can be written out to text file" )
{
	member aMember;
	aMember.addInfo("100000000", "John Doe", "246 Jefferson St", "Portland", "OR", "97201", true, 150.00);
	aMember.writeOut();
}

TEST_CASE ( "check if a provider can be written out to text file" )
{
	provider aProvider;
	aProvider.addInfo("200000000", "John Doe", "246 Jefferson St", "Portland", "OR", "97201", 5, 100.00);
	aProvider.writeOut();
}
