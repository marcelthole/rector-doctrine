<?php

declare(strict_types=1);

namespace Rector\Doctrine\CodeQuality\AnnotationTransformer\PropertyAnnotationTransformer;

use PhpParser\Node\Stmt\Property;
use Rector\BetterPhpDocParser\PhpDocInfo\PhpDocInfo;
use Rector\Doctrine\CodeQuality\Contract\PropertyAnnotationTransformerInterface;
use Rector\Doctrine\CodeQuality\DocTagNodeFactory;
use Rector\Doctrine\CodeQuality\NodeFactory\ArrayItemNodeFactory;
use Rector\Doctrine\CodeQuality\ValueObject\EntityMapping;

final readonly class IdGeneratorAnnotationTransformer implements PropertyAnnotationTransformerInterface
{
    public function __construct(
        private ArrayItemNodeFactory $arrayItemNodeFactory
    ) {
    }

    public function transform(EntityMapping $entityMapping, PhpDocInfo $propertyPhpDocInfo, Property $property): void
    {
        $idMapping = $entityMapping->matchIdPropertyMapping($property);
        if (! is_array($idMapping)) {
            return;
        }

        $generator = $idMapping['generator'] ?? null;
        if (! is_array($generator)) {
            return;
        }

        // make sure strategy is uppercase as constant value
        $generator = $this->normalizeStrategy($generator);

        $arrayItemNodes = $this->arrayItemNodeFactory->create($generator, ['strategy']);

        $spacelessPhpDocTagNode = DocTagNodeFactory::createSpacelessPhpDocTagNode(
            $arrayItemNodes,
            $this->getClassName()
        );
        $propertyPhpDocInfo->addPhpDocTagNode($spacelessPhpDocTagNode);
    }

    public function getClassName(): string
    {
        return 'Doctrine\ORM\Mapping\GeneratedValue';
    }

    /**
     * @param array<string, mixed> $generator
     * @return array<string, mixed>
     */
    private function normalizeStrategy(array $generator): array
    {
        if (isset($generator['strategy']) && $generator['strategy'] === 'auto') {
            $generator['strategy'] = 'AUTO';
        }

        return $generator;
    }
}
