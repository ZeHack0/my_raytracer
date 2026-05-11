/* ------------------------------------------------------------------------------------ *
 *                                                                                      *
 * EPITECH PROJECT - Tue, May, 2026                                                     *
 * Title           - raytracer                                                          *
 * Description     -                                                                    *
 *     PrimitiveFactory                                                                 *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ *
 *                                                                                      *
 *             ███████╗██████╗ ██╗████████╗███████╗ ██████╗██╗  ██╗                     *
 *             ██╔════╝██╔══██╗██║╚══██╔══╝██╔════╝██╔════╝██║  ██║                     *
 *             █████╗  ██████╔╝██║   ██║   █████╗  ██║     ███████║                     *
 *             ██╔══╝  ██╔═══╝ ██║   ██║   ██╔══╝  ██║     ██╔══██║                     *
 *             ███████╗██║     ██║   ██║   ███████╗╚██████╗██║  ██║                     *
 *             ╚══════╝╚═╝     ╚═╝   ╚═╝   ╚══════╝ ╚═════╝╚═╝  ╚═╝                     *
 *                                                                                      *
 * ------------------------------------------------------------------------------------ */

// primitives/PrimitiveFactory.hpp

#pragma once
#include <string>
#include <memory>
#include <libconfig.h++>
#include "IPrimitive.hpp"

class PrimitiveFactory {
    public:
        static std::unique_ptr<IPrimitive>
            create(const std::string& type,
                const libconfig::Setting& cfg);

    private:
        static std::unique_ptr<IPrimitive> makeSphere(const libconfig::Setting&);
        static std::unique_ptr<IPrimitive> makePlane(const libconfig::Setting&);
        static std::unique_ptr<IPrimitive> makeCylinder(const libconfig::Setting&);
        static std::unique_ptr<IPrimitive> makeCone(const libconfig::Setting&);
};
