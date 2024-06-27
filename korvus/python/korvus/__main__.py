import asyncio
from korvus import cli


async def main():
    await cli()


asyncio.run(main())
